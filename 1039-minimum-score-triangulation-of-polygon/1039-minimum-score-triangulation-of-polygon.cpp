class Solution {
    private:
    int solve_TOP_DOWN(vector<int>& values,int i,int j,vector<vector<int>>& dp){
        //base case
        if(i+1 == j)return 0;//no need as we are given there will be more than 3 points

        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans = INT_MAX;
        for(int k=i+1;k<j;k++){
            ans = min(ans,values[i]*values[j]*values[k] + solve_TOP_DOWN(values,i,k,dp)             +                                                         solve_TOP_DOWN(values,k,j,dp)) ;
        }
        dp[i][j] = ans;
        return dp[i][j]; 
    }

    int solve_BOTTOM_UP(vector<int>& values){
        int n = values.size();
        vector<vector<int>> dp(n,vector<int> (n,0));
        // ********* bottom up me just reverse the itertion of i & j********* //
        for(int i = n-1;i>=0;i--){
            for(int j=i+2;j<n;j++)//by base case
            {
                int ans = INT_MAX;
                for(int k = i+1;k<j;k++){
                  ans = min(ans,values[i]*values[j]*values[k] + dp[i][k] + dp[k][j]) ;
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][n-1];
    }
public:
    int minScoreTriangulation(vector<int>& values) {
        // int n = values.size();
        // vector<vector<int>> dp(n,vector<int> (n,-1));
        // return solve_TOP_DOWN(values,0,n-1,dp);
        return solve_BOTTOM_UP(values);
    }
};