class Solution {
public:
    int minimumCost(vector<int>& costs) {
        int n = costs.size();
        sort(costs.begin(),costs.end());

        int ans = 0;
        int cnt = 0;
        for(int i=n-1;i>=0;i--){
            if(cnt == 2){
                cnt = 0;
                continue;
            }

            ans += costs[i];
            cnt++;
        }
        return ans;
    }
};