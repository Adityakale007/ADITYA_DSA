class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        long long count = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                count++;
            } else {
                if (count > 0) {
                    ans += (count * (count + 1)) / 2;
                    count = 0;
                }
            }
        }
        // for last element if it ends with zero
        if (count > 0) {
            ans += (count * (count + 1)) / 2;
        }
        return ans;
    }
};