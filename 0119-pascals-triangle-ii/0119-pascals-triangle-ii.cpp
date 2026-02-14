class Solution {
public:
    vector<int> rec(int rowIndex){
        vector<vector<int>>dp(35,vector<int>(35,-1));
        dp[0][0] = 1;

        for(int i=0;i<=rowIndex;i++){
            dp[i].resize(i+1);
            for(int j=0;j<=i;j++){
                if(j == 0   ||      j==i){
                    dp[i][j] = 1;
                }
                else{
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
            }
        }
        return dp[rowIndex];
    }
    vector<int> getRow(int rowIndex) {
        vector<int> ans = rec(rowIndex);
        return ans;
    }
};