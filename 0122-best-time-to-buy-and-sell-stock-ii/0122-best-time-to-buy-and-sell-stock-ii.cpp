class Solution {
    private:
    int solve_TOP_DOWN(vector<int>& prices,int index,int buy,vector<vector<int>>& dp){
        int n = prices.size();
        //base case
        if(index == n)
            return 0;

        if(dp[index][buy] != -1)
            return dp[index][buy];
        
        int buy_profit = 0;
        int sell_profit = 0;

        if(buy){
            int but_it = -prices[index] + solve_TOP_DOWN(prices,index + 1,0,dp);
            int skip_it = 0 + solve_TOP_DOWN(prices,index + 1,1,dp);
            buy_profit = max(but_it,skip_it);
        }
        else{
            int sell_it = prices[index] + solve_TOP_DOWN(prices,index + 1,1,dp);
            int skip_it = 0 + solve_TOP_DOWN(prices,index + 1,0,dp);
            sell_profit = max(sell_it,skip_it);
        }
        int profit = max(buy_profit,sell_profit);
        return dp[index][buy] = profit;
    }


    int solve_BOTTOM_UP(vector<int>& prices){
        int n = prices.size();
        vector<vector<int>> dp(n + 1,vector<int> (2,0));
        //dp[n][0] = 0
        //dp[n][1] = 0
        for(int index = n-1; index >= 0; index--){
            for(int buy = 0; buy <= 1; buy++){

                int buy_profit = 0;
                int sell_profit = 0;

                if(buy){
                    int but_it = -prices[index] + dp[index + 1][0];
                    int skip_it = 0 + dp[index + 1][1];
                    buy_profit = max(but_it,skip_it);
                }
                else{
                    int sell_it = prices[index] + dp[index + 1][1];
                    int skip_it = 0 + dp[index + 1][0];
                    sell_profit = max(sell_it,skip_it);
                }
                int profit = max(buy_profit,sell_profit);
                dp[index][buy] = profit;
            }
        }
        return dp[0][1];
    }   


    int solve_SPACE_OPTIMISE(vector<int>& prices){
        int n = prices.size();
        // vector<vector<int>> dp(n + 1,vector<int> (2,0));
        //dp[n][0] = 0;
        //dp[n][1] = 0;
        vector<int> currINDEX(2,0);
        vector<int> nextINDEX(2,0);
        //currINDEX[0] = 0;
        //currINDEX[1] = 0;

        for(int index = n-1; index >= 0; index--){
            for(int buy = 0; buy <= 1; buy++){

                int buy_profit = 0;
                int sell_profit = 0;

                if(buy){
                    int but_it = -prices[index] + nextINDEX[0];
                    int skip_it = 0 + nextINDEX[1];
                    buy_profit = max(but_it,skip_it);
                }
                else{
                    int sell_it = prices[index] + nextINDEX[1];
                    int skip_it = 0 + nextINDEX[0];
                    sell_profit = max(sell_it,skip_it);
                }
                int profit = max(buy_profit,sell_profit);
                currINDEX[buy] = profit;
            }
            nextINDEX = currINDEX;
        }
        return nextINDEX[1];
    }   
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>> dp(n,vector<int> (2,-1));
        // return solve_TOP_DOWN(prices,0,1,dp);
        // return solve_BOTTOM_UP(prices);
        return solve_SPACE_OPTIMISE(prices);

    }
};