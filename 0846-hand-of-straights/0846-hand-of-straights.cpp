class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(hand.size() % groupSize != 0)return false;
        //minHeap is increasing in nature when popped out
        priority_queue<int,vector<int>,greater<int>>minHeap;
        unordered_map<int,int>freq;

        for(int h:hand){
            freq[h]++;
        }

        //pushing all unique elements in Heap
        for(auto m:freq){
            minHeap.push(m.first);
        }

        //minheap is used as it gives me small elements while traversing

        while(!minHeap.empty()){
            int start = minHeap.top();

            if(freq[start] == 0){
                minHeap.pop();
                continue;
                //then we will not start from this element to form a sequence
            }

            for(int i=0;i<groupSize;i++){
                int curr = start + i;
                if(freq[curr] == 0)return false;
                freq[curr]--;
            }
        }
        return true;
    }
};