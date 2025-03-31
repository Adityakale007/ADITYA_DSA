class Solution {
    private:
    int solve_TOP_DOWN(int index,vector<int>& prices,int buy,int limit,vector<vector<vector<int>>>& dp){
        int n = prices.size();

        //base case
        if(index == n)
            return 0;

        if(limit == 0)
            return 0;

        if(dp[index][buy][limit] != -1)
            return dp[index][buy][limit];

        int profit_1 = 0;
        int profit_2 = 0;
        if(buy){
            int buy_it = -prices[index] + solve_TOP_DOWN(index + 1,prices,0,limit,dp);
            int skip_it = 0 + solve_TOP_DOWN(index + 1,prices,1,limit,dp);
            profit_1 = max(buy_it,skip_it);
        }
        else{
            int sell_it = prices[index] + solve_TOP_DOWN(index + 1,prices,1,limit - 1,dp);
            int skip_it = 0+ solve_TOP_DOWN(index + 1,prices,0,limit,dp);
            profit_2 = max(sell_it,skip_it);
        }
        int profit = max(profit_1,profit_2);
        return dp[index][buy][limit] = profit;
    }

    int solve_BOTTOM_UP(vector<int>& prices,int k){
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1 , vector<vector<int>> (2 , vector<int> (k+1 , 0)));
        //base acses handelled
            //dp[n][buy][limit] = 0;
            //dp[index][buy][0] = 0;

        for(int index = n-1 ; index >= 0 ; index--){
            for(int buy = 0 ; buy <= 1 ; buy++){
                for(int limit = 1 ; limit <= k ; limit++){

                    int profit_1 = 0;
                    int profit_2 = 0;
                    
                    if(buy){
                        int buy_it = -prices[index] + dp[index+1][0][limit];
                        int skip_it = 0 + dp[index+1][1][limit];
                        profit_1 = max(buy_it,skip_it);
                    }
                    else{
                        int sell_it = prices[index] + dp[index+1][1][limit - 1];
                        int skip_it = 0 + dp[index+1][0][limit];
                        profit_2 = max(sell_it,skip_it);
                    }

                    dp[index][buy][limit] = max(profit_1,profit_2);
                }
            }
        }
        return dp[0][1][k];
    }

    int solve_SPACE_OPTIMSED(vector<int>& prices,int k){
        int n = prices.size();
        // vector<vector<vector<int>>> dp(n+1 , vector<vector<int>> (2 , vector<int> (3 , 0)));
        //base acses handelled
            //dp[n][buy][limit] = 0;
            //dp[index][buy][0] = 0;
        vector<vector<int>> currINDEX(2,vector<int> (k+1 ,0));
        vector<vector<int>> nextINDEX(2,vector<int> (k+1 ,0));

        for(int index = n-1 ; index >= 0 ; index--){
            for(int buy = 0 ; buy <= 1 ; buy++){
                for(int limit = 1 ; limit <= k ; limit++){

                    int profit_1 = 0;
                    int profit_2 = 0;
                    
                    if(buy){
                        int buy_it = -prices[index] + nextINDEX[0][limit];
                        int skip_it = 0 + nextINDEX[1][limit];
                        profit_1 = max(buy_it,skip_it);
                    }
                    else{
                        int sell_it = prices[index] + nextINDEX[1][limit - 1];
                        int skip_it = 0 + nextINDEX[0][limit];
                        profit_2 = max(sell_it,skip_it);
                    }

                    currINDEX[buy][limit] = max(profit_1,profit_2);
                }
            }
            nextINDEX = currINDEX;
        }
        return nextINDEX[1][k];
    }


public:
    int maxProfit(int k, vector<int>& prices) {
         int n = prices.size();
        // vector<vector<vector<int>>> dp(n+1 , vector<vector<int>> (2 , vector<int> (k+1 , -1)));
        // return solve_TOP_DOWN(0,prices,1,k,dp);
        // return solve_BOTTOM_UP(prices,k);
        return solve_SPACE_OPTIMSED(prices,k);
    }
};