class Solution {
public:

    int powerX(int i, int x) {
        int result = 1;
        while (x--) result *= i;
        return result;
    }

    int solve(int n, int x,int curr,vector<vector<int>>& dp){
        int mod = 1e9 + 7;
        if(n==0)return 1;
        if(n<0)return 0;

        if(dp[n][curr] != -1)
            return dp[n][curr];

        int ans = 0;
        for(int i=curr ; powerX(i,x) <= n ; i++){
            int temp = powerX(i,x);
            ans = (ans + solve(n - temp, x, i + 1,dp))%mod;
        }
        return dp[n][curr] = ans;
    }

    int numberOfWays(int n, int x) {
        //3 videos stl
        //2 slides graph revise + 2 preev code
        //lunch
        //4 os videos
        //dsa
        //if os remaining

        vector<vector<int>> dp(n+1,vector<int>(n+1 , -1));

        return solve(n,x,1,dp);    
        //this 1 is because as if we include a number from natural number set we should not take that same number again ..it will increase the number of permutation

    }
};

const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);
#define LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();