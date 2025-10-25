class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        vector<int> ans(grid[0].size());
        long long maxi = 0;

        for(int i=0;i<grid[0].size();i++){
            for(int j=0;j<grid.size();j++){
                string temp = to_string(grid[j][i]);
                long long n = temp.length();
                maxi = max(maxi , n);
            }
                ans[i] = maxi;
                maxi = 0;
        }
        return ans;
    }
};