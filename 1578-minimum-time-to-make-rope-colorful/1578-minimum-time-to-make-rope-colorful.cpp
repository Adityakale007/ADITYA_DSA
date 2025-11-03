class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int total = 0;
        int n = colors.size();

        for (int i = 1; i < n; i++) {
            if (colors[i] == colors[i - 1]) {
                // Remove the smaller one, keep the larger
                total += min(neededTime[i], neededTime[i - 1]);
                // Update to keep the larger cost as the "remaining" one
                neededTime[i] = max(neededTime[i], neededTime[i - 1]);
            }
        }

        return total;
    }
};
