class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        //traversing in each 3x3 matrices
        vector<vector<int>>ans;
        int n = grid.size();

        for(int l=0;l<(n-2);l++){
            vector<int> temp;
            for(int k=0;k<(n-2);k++){
                int maxi = INT_MIN;
                for(int i=l;i<l+3;i++){
                    for(int j=k;j<k+3;j++){
                        maxi = max(maxi , grid[i][j]);
                    }
                }
                temp.push_back(maxi);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};