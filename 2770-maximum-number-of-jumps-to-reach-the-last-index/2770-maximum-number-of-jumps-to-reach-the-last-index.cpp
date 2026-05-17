class Solution {
public:
    int solve(vector<int>& nums, int target,int index,vector<int> &dp){
        int n = nums.size();

        //base case
        if(index >= n)
            return INT_MIN; //infinite steps to reach last  **************  ->
        if(index == n-1)
            return 0;   //is already at last position

        
        if(dp[index] != -1)
            return dp[index];
        

        int ans = INT_MIN;
        int temp = 0; 
        for(int i=index + 1;i < n;i++){     // try all possible next indices
                if(abs(nums[i]  -   nums[index])    <=  target){
                    temp = solve(nums,target,i,dp);
                    if(temp != INT_MIN){
                        ans = max(ans, 1 + temp);
                    }
                    // You defined:
                    // if(index >= n)
                    //     return INT_MIN;
                    // and later:
                    // int ans = INT_MIN;
                    // So throughout the recursion, INT_MIN is acting as the invalid/unreachable marker.
                }
        }
        return dp[index] = ans;
    }
    int maximumJumps(vector<int>& nums, int target) {
        //as in jump only index will change so dp state is one
        int n = nums.size();
        vector<int>dp(n,-1);
        int ans = solve(nums,target,0,dp);

        return ans != INT_MIN ? ans : -1;   //****************** <-
    }
};