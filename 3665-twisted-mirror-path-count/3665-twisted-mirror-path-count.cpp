class Solution {
public:
    int MOD = 1e9 + 7;

    int m,n;

    bool isValid(int i,int j){
        return i>=0&&j>=0&&i<m&&j<n;
    }

    int solve(int i,int j,int m,int n,vector<vector<int>>& grid,vector<vector<int>>& dp){

        if(i==m-1 && j==n-1)return 1;

        if(!isValid(i,j))return 0;

        if(dp[i][j] != -1)
        return dp[i][j];

        long long ans = 0;

        //when going right mirrror changes direction towrds bottom
        if(j+1<n){
            int next_i = i;
            int next_j = j+1;

            if(grid[next_i][next_j] == 1){
                next_i = i + 1;
                next_j = j + 1;
                char dir = 'd';

                while(isValid(next_i,next_j) && grid[next_i][next_j] == 1){
                    if(dir == 'd'){
                        dir = 'r';
                        next_j++;
                    }
                    else{
                        dir = 'd';
                        next_i++;
                    }
                }
            }
            if(isValid(next_i,next_j)) ans = (ans + solve(next_i,next_j,m,n,grid,dp))%MOD;
        }

        //when going down mirrror changes direction towrds right
        if(i+1<m){
            int next_i = i + 1;
            int next_j = j;

            if(grid[next_i][next_j] == 1){
                next_i = i + 1;
                next_j = j + 1;
                char dir = 'r';

                while(isValid(next_i,next_j) && grid[next_i][next_j] == 1){
                    if(dir == 'd'){
                        dir = 'r';
                        next_j++;
                    }
                    else{
                        dir = 'd';
                        next_i++;
                    }
                }
            }
            if(isValid(next_i,next_j)) ans = (ans + solve(next_i,next_j,m,n,grid,dp))%MOD;
        }

        return dp[i][j] = ans%MOD;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<int>> dp(m+1,vector<int>(n+1 , -1));

        return (int)solve(0,0,m,n,grid,dp);
    }
};