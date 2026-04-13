class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // for finding in sliding window
        int n = nums.size();
        vector<int>ans;

        //as maximum
        deque<int>dq; //this is a decreasing deque

        //traverse for first k-sized window
        for(int i=0;i<k;i++){
            //addition logic
            while(!dq.empty()      &&      nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        //storing in ans
        if(!dq.empty()){
            ans.push_back(nums[dq.front()]);
        }


        //for remaining k -> n array
        for(int i=k;i<n;i++){
            //removal logic
            if(!dq.empty()      &&      (i - dq.front() >= k)){
                dq.pop_front();
            }

            //addition logic
            while(!dq.empty()      &&      nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);

            if(!dq.empty()){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};