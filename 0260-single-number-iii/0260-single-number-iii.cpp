class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> nums2;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if ((i == 0 || nums[i] != nums[i - 1]) && (i == n - 1 || nums[i] != nums[i + 1])) {
                nums2.push_back(nums[i]);
            }
            if (nums2.size() == 2)
                break;
        }

        return nums2;
    }
};