class Solution {
public:
    bool gridCheck(int x,int y,vector<vector<int>>& grid){
        if(grid[x + 1][y + 1] != 5)
            return false;   //centre must be 5 if elemnts are distinct
        
        unordered_map<int,int>mp;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(grid[i+x][j+y] >= 1 && grid[i+x][j+y] <= 9){
                    mp[grid[i + x][j + y]]++;
                }
                else{
                    return false;
                }
            }
        }
        if(mp.size() != 9)return false;

        int rowSUM = 0;
        int colSUM = 0;
        int diagonalSUM = 0;

        for(int j=0;j<3;j++){
            rowSUM += grid[0 + x][j + y];
        }
        for(int i=0;i<3;i++){
            colSUM += grid[i + x][0 + y];
        }
        diagonalSUM = grid[1 + x][1 + y] + grid[2 + x][0 + y] + grid[0 + x][2 + y] ;

        for(int i=1;i<3;i++){
            int rowCheck = 0;
            for(int j=0;j<3;j++){
                rowCheck += grid[i + x][j + y];
            }
            if(rowCheck != rowSUM)return false;
        }
        for(int i=1;i<3;i++){
            int colCheck = 0;
            for(int j=0;j<3;j++){
                colCheck += grid[j + x][i + y];
            }
            if(colCheck != colSUM)return false;
        }
        int diagonlCheck = grid[0 + x][0 + y] + grid[1 + x][1 + y] + grid[2 + x][2 + y];
        if(diagonlCheck != diagonalSUM)return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int cnt = 0;
        int n = grid.size();
        int m = grid[0].size();

        if(n<3 || m<3)return 0;

        for(int i=0;i+2<n;i++){
            for(int j=0;j+2<m;j++){
                if(gridCheck(i,j,grid))cnt++;
            }
        }

        return cnt;
    }
};