class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //create a max heap 
        //and pop k times
        int n = nums.size();

        // priority_queue<int,vector<int>,greater<int>> minHeap;
        priority_queue<int> maxHeap;
        
        for(int i=0;i<n;i++){
            maxHeap.push(nums[i]);
        }

        while(k>1){
            maxHeap.pop();
            k--;
        }
        return maxHeap.top();
    }
};