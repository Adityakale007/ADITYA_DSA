#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0 || n >= k + maxPts) return 1.0;

        vector<double> dp(n + 1, 0.0);
        dp[0] = 1.0;
        double W = 1.0;   // sliding window sum
        double result = 0.0;

        for (int i = 1; i <= n; i++) {
            dp[i] = W / maxPts;

            if (i < k) {
                W += dp[i];  // still drawing
            } else {
                result += dp[i];  // stopping point
            }

            if (i - maxPts >= 0) {
                W -= dp[i - maxPts];  // slide window
            }
        }
        return result;
    }
};
