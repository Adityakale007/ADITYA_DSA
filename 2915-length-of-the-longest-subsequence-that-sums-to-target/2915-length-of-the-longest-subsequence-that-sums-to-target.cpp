//knapsack algorithm
//like coin change
class Solution {
    private:
        int solve_TOP_DOWN(vector<int>& nums,int index,int target,vector<vector<int>>& dp){
        int n = nums.size();
        //base case
        if(target == 0)
            return 0;
        if(index >= n)
            return INT_MIN;//that means we didn't got answer

        if(dp[index][target] != -1) 
            return dp[index][target];
            
        int Take = INT_MIN;
        int temp = 0;
        if(target - nums[index] >= 0) ///////////////////////*********
        {
            temp = solve_TOP_DOWN(nums,index + 1,target - nums[index],dp);
            if(temp != INT_MIN){
                Take = 1 + temp;
            }
        }
        int NotTake = 0 + solve_TOP_DOWN(nums,index + 1,target,dp);
        
        return dp[index][target] = max(Take,NotTake);
    }

    int solve_BOTTOM_UP(vector<int>& nums,int target){
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(target+1,INT_MIN)); // 2nd base case solved
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }// 1st base case solved
        
        for(int index = n-1;index>=0;index--){
            for(int diff = 0 ; diff <= target ; diff++){
                int Take = INT_MIN;
                int temp = 0;
                if(diff - nums[index] >= 0) ///////////////////////*********
                {
                    temp = dp[index + 1][diff - nums[index]];
                    if(temp != INT_MIN){
                        Take = 1 + temp;
                    }
                }
                int NotTake = 0 + dp[index + 1][diff];
                
                    dp[index][diff] = max(Take,NotTake);
                }
            }
            if(dp[0][target] == INT_MIN)
                return -1;
            
            return dp[0][target];

        }

        int solve_SPACE_OPTIMISE(vector<int>& nums,int target){
        int n = nums.size();
        // vector<vector<int>> dp(n+1,vector<int>(target+1,INT_MIN)); // 2nd base case solved
        // for (int i = 0; i <= n; i++) {
        //     dp[i][0] = 0;
        // }// 1st base case solved
        vector<int> currINDEX(target+1,INT_MIN);   // 2nd base case solved
        vector<int> nextINDEX(target+1,INT_MIN);   // 2nd base case solved

            nextINDEX[0] = 0; // 1st base case solved
        
        for(int index = n-1;index>=0;index--){
            for(int diff = 0 ; diff <= target ; diff++){
                int Take = INT_MIN;
                int temp = 0;
                if(diff - nums[index] >= 0) ///////////////////////*********
                {
                    temp = nextINDEX[diff - nums[index]];
                    if(temp != INT_MIN){
                        Take = 1 + temp;
                    }
                }
                int NotTake = 0 + nextINDEX[diff];
                
                    currINDEX[diff] = max(Take,NotTake);
                }
                nextINDEX = currINDEX;
            }
            if(nextINDEX[target] == INT_MIN)
                return -1;
            
            return nextINDEX[target];

        }
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        // vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        // int length =  solve_TOP_DOWN(nums,0,target,dp);
        // if(length == INT_MIN)
        //     return -1;
        // return length;
        // return  solve_BOTTOM_UP(nums,target);
        return  solve_SPACE_OPTIMISE(nums,target);
    }
};