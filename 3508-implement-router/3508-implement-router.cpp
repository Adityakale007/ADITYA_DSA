#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <set>    // For a cleaner way to track duplicates
#include <tuple>  // To use as the key in the set
#include <utility> // For std::pair

// Required headers for the ordered_set (PBDS)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

// Using declarations for convenience
using namespace std;
using namespace __gnu_pbds;

// Define a type for our ordered_set for cleaner code
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Router {
private:
    // Packet struct remains the same
    struct Packet {
        int source, destination, timestamp;
    };

    int memoryLimit;
    deque<Packet> q;                             // For FIFO order
    set<tuple<int, int, int>> seen;              // O(log N) check for duplicates, cleaner than string keys
    
    // The key optimization: maps destination to an ordered_set of {timestamp, source} pairs
    unordered_map<int, ordered_set<pair<int, int>>> destMap; 

public:
    Router(int memoryLimit) {
        this->memoryLimit = memoryLimit;
    }

    bool addPacket(int source, int destination, int timestamp) {
        tuple<int, int, int> key = {source, destination, timestamp};
        if (seen.count(key)) {
            return false; // Duplicate packet
        }

        // If memory is full, evict the oldest packet
        if (q.size() >= memoryLimit) {
            Packet old = q.front();
            q.pop_front();

            tuple<int, int, int> oldKey = {old.source, old.destination, old.timestamp};
            seen.erase(oldKey);
            
            // Also remove from our optimized destMap
            destMap[old.destination].erase({old.timestamp, old.source});
            if (destMap[old.destination].empty()) {
                destMap.erase(old.destination);
            }
        }

        // Add the new packet to all data structures
        q.push_back({source, destination, timestamp});
        seen.insert(key);
        destMap[destination].insert({timestamp, source});
        return true;
    }

    vector<int> forwardPacket() {
        if (q.empty()) {
            return {};
        }

        Packet pkt = q.front();
        q.pop_front();

        // Remove the packet from all data structures
        tuple<int, int, int> key = {pkt.source, pkt.destination, pkt.timestamp};
        seen.erase(key);
        
        destMap[pkt.destination].erase({pkt.timestamp, pkt.source});
        if (destMap[pkt.destination].empty()) {
            destMap.erase(pkt.destination);
        }
        
        return {pkt.source, pkt.destination, pkt.timestamp};
    }

    // O(log K) complexity, where K is the number of packets for this destination
    int getCount(int destination, int startTime, int endTime) {
        // If there are no packets for this destination, return 0
        if (destMap.find(destination) == destMap.end()) {
            return 0;
        }

        auto& os = destMap.at(destination);

        // Count packets with timestamp <= endTime
        // This is the number of elements strictly less than {endTime + 1, 0}
        int count_le_end = os.order_of_key({endTime + 1, 0});

        // Count packets with timestamp < startTime
        // This is the number of elements strictly less than {startTime, 0}
        int count_lt_start = os.order_of_key({startTime, 0});

        return count_le_end - count_lt_start;
    }
};