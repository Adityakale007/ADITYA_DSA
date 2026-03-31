class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        //brute force -> scan to each and every window
        // int l = 0;
        // int r = k-1;
        // vector<int>ans;
        // while(r<n){
        //     int maxi = INT_MIN;
        //     for(int i=l;i<=r;i++){
        //         maxi = max(maxi,nums[i]);
        //     }
        //     ans.push_back(maxi);
        //     l++;
        //     r++;
        // }
        // return ans;
        //TC -> O(N2)

        

        //so here we use double ended queue (dequeue)   ->  DQ
        //in window -> to insert from one end and to remove from other end
        //push_front()
        //pop_front()
        //push_back()
        //pop_back()

        //we will store in monotonic decreasing fashion
        deque<int> dq;
        vector<int> ans;

        for(int i=0;i<n;i++){
            //if window is moved and the previous windows largest element is not present in current window
            //remove only one element as window moved only by one
            if(!dq.empty()  &&  dq.front() <= (i-k)){
                dq.pop_front();
            }

            // storing in monotonic decreasing fashion
            while(!dq.empty()   &&  nums[dq.back()] <=  nums[i]){
                dq.pop_back();
            }

            dq.push_back(i);    //store index

            if(i >= k-1){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};