class Solution {
private:
    int solve_TOP_DOWN(vector<int>& nums, int index, vector<int>& dp) {
        int n = nums.size();
        // base case
        if (index >= n)
            return 0;
        if (index == n - 1) // on the target
            return 0;

        if (dp[index] != -1) {
            return dp[index];
        }

        int ans = INT_MAX;
        int temp = 0;
        for (int i = 1; i <= nums[index]; i++) {
            if (index + i < n) {
                int temp = dp[index + i];
                if (temp != INT_MAX) {
                    ans = min(ans, 1 + temp);
                }
            }
        }

        return dp[index] = ans;
    }

    int solve_BOTTOM__UP(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 2, INT_MAX); //as i have to find minimum
        dp[n-1] = 0;

        for (int index = n - 2; index >= 0; index--) {
            int ans = INT_MAX;
            int temp = 0;
            for (int i = 1; i <= nums[index]; i++) {
                //recursive relation ::
                //ans = min(ans , 1 + solve_TOP_DOWN(nums,index + i))
                if (index + i < n) {
                    int temp = dp[index + i];
                    if (temp != INT_MAX) {
                        ans = min(ans, 1 + temp);
                    }
                }
            }
            dp[index] = ans;
        }
        return dp[0];
    }

public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp(n+1,-1);
        // return solve_TOP_DOWN(nums,0,dp);
        return solve_BOTTOM__UP(nums);
    }
};