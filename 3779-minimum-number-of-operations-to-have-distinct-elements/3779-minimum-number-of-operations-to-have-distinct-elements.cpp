class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(100001, 0);
        int duplicates = 0;

        // Initial frequency count
        for (int x : nums) {
            if (++freq[x] == 2) {
                duplicates++;
            }
        }

        // If already distinct
        if (duplicates == 0) return 0;

        int ops = 0;
        int idx = 0;

        // Remove elements in groups of 3
        while (idx < n) {
            ops++;
            for (int j = 0; j < 3 && idx < n; j++, idx++) {
                int val = nums[idx];
                if (freq[val] == 2) {
                    duplicates--;
                }
                freq[val]--;
            }

            if (duplicates == 0) {
                return ops;
            }
        }

        return ops;
    }
};
