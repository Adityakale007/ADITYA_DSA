class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        long long ans = 0;
        long long res = k;
        long long t = 0;
        for(int i=0;i<n;i++){
            // while(res < nums[i]){
            //     res += k;
            //     ans += ++t;
            // }
            //as res + x.k >= nums[i]
            //x = (nums[i] - res )/ k

            if(res < nums[i]){
                // long long x = ceil((nums[i] - res) / k);
                long long x = ((nums[i] - res + k - 1) / k);
                // ans += ((x * (2*t + x + 1))/2);
                __int128 cost = (__int128)x * (2 * (__int128)t + x + 1) / 2;
                ans = (ans + (long long)(cost % MOD)) % MOD;
                res += x*k;
                t += x;
            }
            res -= nums[i];
            ans % MOD;
        }
        return ans % MOD;
    }
};