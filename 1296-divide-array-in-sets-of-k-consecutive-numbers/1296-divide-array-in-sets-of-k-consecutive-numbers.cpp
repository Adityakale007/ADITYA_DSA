class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if(nums.size() % k != 0)return false;
        //minHeap is increasing in nature when popped out
        priority_queue<int,vector<int>,greater<int>>minHeap;
        unordered_map<int,int>freq;

        for(int n:nums){
            freq[n]++;
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

            for(int i=0;i<k;i++){
                int curr = start + i;
                if(freq[curr] == 0)return false;
                freq[curr]--;
            }
        }
        return true;
    }
};