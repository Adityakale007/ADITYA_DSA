class Solution {
    private:
    bool solve_TOP_DOWN(vector<int>& nums,int index,vector<int>& dp){
        int n = nums.size();
        //base case
        if(index >= n)
            return false;/////////
        if(index == n-1)
            return true;////////

        if(dp[index] != -1)
            return dp[index];

        bool ans = false;
        bool temp = false;
        for(int i = 1;i <= nums[index];i++){
            if(index + i < n){
                temp = solve_TOP_DOWN(nums,index + i,dp);
                ans = ans || temp;  ////////////////////////////////////////////////
                ////// OR ///////
                // if (solve_TOP_DOWN(nums, index + i, dp)) {
                //     ans = true;
                //     break;  // No need to check further once we found a path
                // }
            }
        }
       return dp[index] = ans;
    }

    bool solve_BOTTOM_UP(vector<int>& nums){
        int n = nums.size();
        vector<int> dp(n+1,false);
        dp[n-1] = true;

        for(int index = n-2;index >= 0;index--){
            bool ans = false;
            bool temp = false;
            for(int i =1;i <= nums[index];i++){
                if(index + i < n){
                    temp = dp[index + i];
                    ans = ans || temp;
                }
            }
            dp[index] = ans;
        }
        return dp[0];
    }
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp(n+1,-1);
        // return solve_TOP_DOWN(nums,0,dp);
        return solve_BOTTOM_UP(nums);
    }
};