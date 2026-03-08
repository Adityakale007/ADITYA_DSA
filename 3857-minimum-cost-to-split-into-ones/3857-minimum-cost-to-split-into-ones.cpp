class Solution {
public:
    int dp[501];
    int rec(int n){
        if(n==1)return 0;

        if(dp[n] != -1)return dp[n];

        int ans = INT_MAX;

        for(int a = 1;a<n;a++){
            int b = n-a;
            ans = min(ans,a*b + rec(a) + rec(b));
            //current split cost + cost to split a + cost to split b
        }
        return dp[n] = ans;
    }
    int minCost(int n) {
        memset(dp,-1,sizeof(dp));
        return rec(n);
    }
};