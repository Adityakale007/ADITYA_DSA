class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> temp(n,vector<int>(m,0));

        vector<int> rowMax(n);
        vector<int> colMax(m);
        int i = 0;
        int j = 0;

        while(i<n){
            for(int j=0;j<m;j++){
                rowMax[i] = max(rowMax[i],grid[i][j]);
            }
            i++;
        }


        while(j<m){
            for(int i=0;i<n;i++){
                colMax[j] = max(colMax[j],grid[i][j]);
            }
            j++;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                temp[i][j] = min(rowMax[i],colMax[j]);
            }
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans += temp[i][j] - grid[i][j];
            }
        }
        return ans;
    }
};