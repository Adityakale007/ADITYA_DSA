#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9 + 7;
        vector<long long> dp(n + 1, 0); 
        dp[1] = 1; // day 1: one person discovers

        for (int i = 1; i <= n; i++) {
            for (int j = i + delay; j < min(n + 1, i + forget); j++) {
                dp[j] = (dp[j] + dp[i]) % MOD;
            }
        }

        long long ans = 0;
        for (int i = n - forget + 1; i <= n; i++) {
            if (i >= 1) ans = (ans + dp[i]) % MOD;
        }
        return (int)ans;
    }
};
