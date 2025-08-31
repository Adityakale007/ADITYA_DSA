class Solution {
public:
    int solve(int i,int j,int m,int n,int count,vector<vector<int>>& grid){
        if(i<0 || j<0)return 0;
        if(i>=grid.size() || j>=grid[0].size())return 0;
        if(grid[i][j] == -1)return 0;

        if(i == m && j == n){
            if(count == 0)return 1;
            return 0;
        }

        int temp = grid[i][j];
        grid[i][j] = -1;

        int up = solve(i-1,j,m,n,count-1,grid);
        int down = solve(i+1,j,m,n,count-1,grid);
        int right = solve(i,j+1,m,n,count-1,grid);
        int left = solve(i,j-1,m,n,count-1,grid);

        grid[i][j] = temp;

        return up+down+right+left;
    }
    

    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int src_i=0;
        int src_j=0;

        int tar_i=0;
        int tar_j=0;

        int count = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 0){
                    count++;
                }
                else if(grid[i][j] == 1){
                    src_i = i;
                    src_j = j;
                }
                else if(grid[i][j] == 2){
                    tar_i = i;
                    tar_j = j;
                }
            }
        }

        return solve(src_i,src_j,tar_i,tar_j,count+1,grid);//count+1 as includiing starting square
    }
};