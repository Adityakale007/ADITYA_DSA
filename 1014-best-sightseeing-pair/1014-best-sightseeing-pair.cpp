class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        vector<int> values1 = values;
        vector<int> values2 = values;

        for(int i=0;i<n;i++){
            values1[i] += i;
        }

        for(int i=0;i<n;i++){
            values2[i] -= i;
        }

        int ans = INT_MIN;
        int left = values1[0];

        for(int i=1;i<n;i++){
            ans = max(ans , left + values2[i]);
            left = max(left,values1[i]);
        }
        return ans;
    }
};