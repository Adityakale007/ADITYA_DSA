class Solution {
public:
    int n;
    int m;
    // int dp[201][201][1001]; -> giving run time error as dp size is huge
    vector<vector<vector<int>>>dp;

    int rec(int i,int j,vector<vector<int>>& grid,int cost,int k){
        if(i>=m ||  j>= n)return -1e9;

        int newCost = cost + (grid[i][j] != 0);
        if(newCost > k) return -1e9;

        if(i == m-1 &&  j == n-1)return grid[i][j];

        if(dp[i][j][newCost] != -1){
            return dp[i][j][newCost];
        }

        int right = rec(i,j+1,grid,newCost,k);
        int down = rec(i+1,j,grid,newCost,k);

        return dp[i][j][newCost] = (grid[i][j]   +   max(right,down));
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        // memset(dp,-1,sizeof(dp));
        dp.assign(m,vector<vector<int>>(n,vector<int>(k+1,-1)));

        int ans = rec(0,0,grid,0,k);

        return ((ans < 0) ?  -1 :  ans);
    }
};