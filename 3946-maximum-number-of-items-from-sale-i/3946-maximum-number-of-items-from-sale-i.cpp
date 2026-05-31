class Solution {
public:
    // static bool fxn(vector<int> &a , vector<int> &b){
    //     return a[1] < b[1];
    // }
    int mini_Price = INT_MAX;


    int rec(vector<vector<int>>& items, int budget,vector<int> &bonus,int index,vector<vector<int>> &dp){
        int n = items.size();

        //base case
        if(budget < 0){
            return INT_MIN; //as we need maximum
        }
        if(index >= n){
            return budget/mini_Price;    
            // After selecting all “first purchases” (which give bonuses),
            // remaining money should be spent on cheapest item.
        }
        
        if(dp[index][budget] != -1)
            return dp[index][budget];

        //this is one go -> no need to wory about visited to add bonus one more time
        int price = items[index][1];
        //only include / exclude
        int include = 1 + bonus[index] + rec(items,budget - price,bonus,index + 1,dp);
        int exclude = rec(items,budget,bonus,index + 1,dp);

        return dp[index][budget] = max(include,exclude);
    }   


    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        // does NOT give extra free rewards
        // So:
        // first purchase of item type i activates its free bonus
        // additional copies only increase purchased count
        int n = items.size();
        vector<int>bonus(n);        //for calculating free copies

        for(int i=0;i<n;i++){
            int cnt = 0;
            for(int j=0;j<n;j++){
                if(i!=j &&  items[j][0]%items[i][0] == 0){
                    cnt++;
                }
            }
            mini_Price = min(mini_Price,items[i][1]);
            bonus[i] = cnt;
        }

        // sort(items.begin(),items.end(),fxn);    //sorting based on prices 

        //dp -> knsapsack solution
        // n <= 1000
        // budget <= 1500
        // This strongly hints:
        // DP / knapsack solution

        vector<vector<int>>dp(n+1,vector<int> (budget+1 , -1));

        return rec(items,budget,bonus,0,dp);
    }
};