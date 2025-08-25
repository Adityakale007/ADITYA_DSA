class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        vector<int> pos(n), amt(n);
        for (int i = 0; i < n; i++) {
            pos[i] = fruits[i][0];
            amt[i] = fruits[i][1];
        }

        // prefix sum
        vector<long long> prefix(n+1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i+1] = prefix[i] + amt[i];
        }

        auto rangeSum = [&](int l, int r) {
            return prefix[r+1] - prefix[l];
        };

        int ans = 0;
        int left = 0;
        for (int right = 0; right < n; right++) {
            // shrink left if distance > k
            while (left <= right) {
                int L = max(0, startPos - pos[left]);
                int R = max(0, pos[right] - startPos);
                int steps = min(L, R) * 2 + max(L, R);
                if (steps <= k) break;
                left++;
            }
            if (left <= right) {
                ans = max(ans, (int)rangeSum(left, right));
            }
        }
        return ans;
    }
};