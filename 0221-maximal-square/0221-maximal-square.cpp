class Solution {
private:
    int solve_TOP_DOWN(vector<vector<char>>& matrix, int i, int j, int &maxi,vector<vector<int>>& dp) {
        // base case
        if (i >= matrix.size() || j >= matrix[0].size())
            return 0;

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int right = solve_TOP_DOWN(matrix, i + 1, j, maxi, dp);
        int bottom = solve_TOP_DOWN(matrix, i, j + 1, maxi, dp);
        int diagonal = solve_TOP_DOWN(matrix, i + 1, j + 1, maxi, dp);
        if (matrix[i][j] == '1') {
            dp[i][j] = 1 + min(right,min(bottom, diagonal)); // minimum as it should be a square
            maxi = max(maxi, dp[i][j]);
            return dp[i][j]; //doesn't matter as we are returning maxi
        } else {
            return dp[i][j] = 0;//doesn't matter as we are returning maxi
        }
    }


    int solve_BOTTOM_UP(vector<vector<char>>& matrix,int &maxi) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> dp(row+1,vector<int>(col+1, 0));
        for(int i = row-1;i>=0;i--){
            for(int j = col-1;j>=0;j--){
                int right = dp[i+1][j];
                int bottom = dp[i][j+1];
                int diagonal = dp[i+1][j+1];
                if (matrix[i][j] == '1') {
                    dp[i][j] = 1 + min(right,min(bottom, diagonal)); // minimum as it should be a square
                    maxi = max(maxi, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return dp[0][0];//doesn't matter as we are returning maxi
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi = 0;
        // vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(), -1));
        // solve_TOP_DOWN(matrix, 0, 0, maxi, dp);
        solve_BOTTOM_UP(matrix,maxi);
        return maxi*maxi;//as area is asked
    }
};