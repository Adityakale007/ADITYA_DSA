class Solution {
public:
    int m,n;
    int dp[201][201];

    int rec(int i,int j,vector<vector<int>>& d){
        if(i >= m   ||  j >= n)return 1e9;
        if(i == m-1 &&   j== n-1)return max(1 , 1 - d[i][j]);

        if(dp[i][j] != -1)
            return dp[i][j];

        int right = rec(i,j+1,d);
        int down = rec(i+1,j,d);

        int need = min(right,down) - d[i][j];

        return dp[i][j] = max(1,need);

        //dry ran from bottom we affirmed that
        //when d[i][j] > 0  -> need should be subtracted 
        //when d[i][j] < 0  -> need should be added 
    }


    int calculateMinimumHP(vector<vector<int>>& d) {
        m = d.size();
        n = d[0].size();

        memset(dp,-1,sizeof(dp));
        int ans = rec(0,0,d);
        
        return ans;
    }
};