class Solution {
    private:
    int solve_TOP_DOWN(int start_index,int end_index,vector<vector<int>>& dp){
        //base case
        if(start_index >= end_index)
            return 0;

        if(dp[start_index][end_index] != -1){
            return dp[start_index][end_index];
        }

        int ans = INT_MAX;
        for(int i=start_index;i<=end_index;i++){
            ans = min(ans,i + max(solve_TOP_DOWN(start_index,i-1,dp),
            solve_TOP_DOWN(i+1,end_index,dp)));
        }
        return dp[start_index][end_index] = ans;
    }

    int solve_BOTTOM_UP(int n){
        vector<vector<int>> dp(n+2,vector<int> (n+2,0));
        //base cases handelled

        for(int start_index = n; start_index >= 1 ; start_index-- ){
            for(int end_index = start_index ; end_index <= n ; end_index++){

                if(start_index == end_index)
                    continue;
                else{
                    int ans = INT_MAX;
                    for(int i=start_index;i<=end_index;i++){
                        int temp = max( dp[start_index][i-1] , dp[i+1][end_index] );
                        ans = min(ans,i + temp);
                    }
                    dp[start_index][end_index] = ans;
                    }
            }
        }
        return dp[1][n];
    }
public:
    int getMoneyAmount(int n) {
        // vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        // return solve_TOP_DOWN(1,n,dp);
        return solve_BOTTOM_UP(n);
    }
};