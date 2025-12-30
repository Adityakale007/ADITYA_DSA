class Solution {
public:
    bool gridCheck(int x,int y,int k,vector<vector<int>>& grid){
        int targetSum = 0;

        for(int j=0;j<k;j++){
            targetSum += grid[0 + x][j + y];
        }

        for(int i=0;i<k;i++){
            int rowCheck = 0;
            for(int j=0;j<k;j++){
                rowCheck += grid[i + x][j + y];
            }
            if(rowCheck != targetSum)return false;
        }
        for(int i=0;i<k;i++){
            int colCheck = 0;
            for(int j=0;j<k;j++){
                colCheck += grid[j + x][i + y];
            }
            if(colCheck != targetSum)return false;
        }

        //main diagonal
        int diagonlCheck = 0;
        for(int i=0;i<k;i++){
            diagonlCheck += grid[x + i][y + i];
        }
        if(diagonlCheck != targetSum)return false;

        //anti diagonal
        diagonlCheck = 0;
        for(int i=0;i<k;i++){
            diagonlCheck += grid[x + i][y + k - 1 - i];
        }
        if(diagonlCheck != targetSum)return false;

        return true;
    }


    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int maxi = min(n,m);

        for(int k = maxi;k>1;k--){
            for(int i=0;i+k<=n;i++){
                for(int j=0;j+k<=m;j++){
                    if(gridCheck(i,j,k,grid)){
                        return k;
                    }
                }
            }
        }
        return 1;//for 1x1
    }
};