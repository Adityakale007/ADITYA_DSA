class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> count;
        int n = basket1.size();
        long long minGlobal = 1e18;

        // Count frequencies
        for (int x : basket1) {
            count[x]++;
            minGlobal = min(minGlobal, (long long)x);
        }
        for (int x : basket2) {
            count[x]++;
            minGlobal = min(minGlobal, (long long)x);
        }

        // Check feasibility
        for (auto &p : count) {
            if (p.second % 2 != 0) return -1;
        }

        // Compute imbalance
        unordered_map<int,int> freq1, freq2;
        for (int x : basket1) freq1[x]++;
        for (int x : basket2) freq2[x]++;

        vector<int> mismatch; // fruits that must be moved
        for (auto &p : count) {
            int x = p.first;
            int diff = abs(freq1[x] - freq2[x]) / 2;
            for (int k = 0; k < diff; k++) {
                mismatch.push_back(x);
            }
        }

        // Sort mismatches so we try cheapest first
        sort(mismatch.begin(), mismatch.end());

        long long cost = 0;
        int m = mismatch.size();
        for (int i = 0; i < m/2; i++) {
            cost += min((long long)mismatch[i], 2 * minGlobal);
        }

        return cost;
    }
};