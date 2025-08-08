class Solution {
public:

    double solve(int n,double a,double b,vector<vector<double>>& dp){
        //base case
        if(a<=0 && b<=0)return 0.5;
        if(a<=0)return 1;
        if(b<=0)return 0;

        if(dp[a][b] != -1)
            return dp[a][b];
        
        double ans = 0.25*(solve(n,a-4,b,dp) + solve(n,a-3,b-1,dp) + solve(n,a-2,b-2,dp) + solve(n,a-1,b-3,dp));
        
        return dp[a][b] = ans;
    }

    double soupServings(int n) {
        if(n>=5000)return 1;
        int m = ceil((double)n / 25);

        vector<vector<double>> dp(n+1 , vector<double>(n+1 , -1));
        return solve(n,m,m,dp) ;
    }
};