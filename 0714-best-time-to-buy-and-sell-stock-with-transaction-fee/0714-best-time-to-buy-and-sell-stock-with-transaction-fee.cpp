class Solution {
    private:
    int solve_TOP_DOWN(vector<int>& prices, int fees,int index,int buy,vector<vector<int>>& dp){
        int n = prices.size();
        //base case
        if(index == n)
            return 0;

        if(dp[index][buy] != -1)
            return dp[index][buy];
        
        int profit_1 = 0;
        int profit_2 = 0;
        if(buy){
            int buy_it = -prices[index] + solve_TOP_DOWN(prices,fees,index + 1,0,dp);
            int skip_it = 0 + solve_TOP_DOWN(prices,fees,index + 1,1,dp);
            profit_1 = max(buy_it,skip_it);
        }
        else{
            int sell_it = prices[index] + solve_TOP_DOWN(prices,fees,index + 1,1,dp) - fees;
            int skip_it = 0 + solve_TOP_DOWN(prices,fees,index + 1,0,dp);
            profit_2 = max(sell_it,skip_it);
        }
        int profit = max(profit_1,profit_2);
        return dp[index][buy] = profit;
    }

    int solve_SPACE_OPTIMESED(vector<int>& prices, int fees){
        int n = prices.size();
        // vector<vector<int>> dp(n+1 , vector<int> (2 , 0));       
        //base cases cleared
            //dp[n][buy] = 0 

        vector<int> currINDEX(2 , 0);
        vector<int> nextINDEX(2 , 0);

        for(int index = n-1 ; index>=0 ; index--){
            for(int buy = 0; buy<=1 ; buy++){

                int profit_1 = 0;
                int profit_2 = 0;
                if(buy){
                    int buy_it = -prices[index] + nextINDEX[0];
                    int skip_it = 0 + nextINDEX[1];
                    profit_1 = max(buy_it,skip_it);
                }
                else{
                    int sell_it = prices[index] + nextINDEX[1] - fees;
                    int skip_it = 0 + nextINDEX[0];
                    profit_2 = max(sell_it,skip_it);
                }
                int profit = max(profit_1,profit_2);
                currINDEX[buy] = profit;
            }
            nextINDEX = currINDEX ;
        }
        return nextINDEX[1];
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        // vector<vector<int>> dp(n+1 , vector<int> (2 , -1));
        // return solve_TOP_DOWN(prices,fee,0,1,dp);
        // return solve_BOTTOM_UP(prices,fee);
        return solve_SPACE_OPTIMESED(prices,fee);
    }
};