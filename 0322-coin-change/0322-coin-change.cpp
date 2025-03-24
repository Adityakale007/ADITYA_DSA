class Solution {
private:
    int solve_TOP_to_BOTTOM(vector<int>& coins, int amount, vector<int>& dp) {
        // base case
        if (amount == 0)
            return 0;
        if (amount < 0)
            return INT_MAX;

        // step 3
        if (dp[amount] != -1) {
            return dp[amount];
        }

        int mini = INT_MAX;
        for (int i = 0; i < coins.size(); i++) {
            int ans = solve_TOP_to_BOTTOM(coins, amount - coins[i], dp);
            if (ans != INT_MAX) {
                mini = min(mini, 1 + ans);//1+ as also cosidering coins[i]
            }
        }
        dp[amount] = mini;
        return dp[amount];
    }
    


    int solve_BOTTOM_UP(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);

        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if((i - coins[j] >= 0)&&(dp[i - coins[j]] != INT_MAX)){
                    //i - coins[j] >= 0 as theere is no condition for dp[<0]
                   dp[i] = min(dp[i] , 1 + dp[i - coins[j]]);
                }
            }
        }
        if(dp[amount] == INT_MAX){
            return -1;
        }
        return dp[amount];
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // vector<int> dp(amount + 1,-1);
        //int ans = solve(coins, amount, dp);
        //if (ans == INT_MAX) {
        //    return -1;
        //}
        //return ans;
        return solve_BOTTOM_UP(coins,amount);
    }
};