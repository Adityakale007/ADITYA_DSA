class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        //using monotonic stack
        //in decreasing order
        int n = nums.size();
        stack<int> s;
        vector<int>ans(n,-1);
        for(int i=2*n-1;i>=0;i--){
            while(!s.empty()    &&  nums[i%n] >= s.top()){
                    s.pop();
            }
            if(i<n){
                //nums[i] < s.top()
                if(!s.empty()){
                    ans[i] = s.top();
                }
            }
            s.push(nums[i%n]);
        }
        return ans;
    }
};