class Solution {
public:
    vector<pair<int, int>> directions = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2},
                                         {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

    int startRow;
    int startCol;
    int N;

        double solve(int i, int j, int moves,vector<vector<vector<double>>>& dp) {
        if (moves == 0) {
            if (i == startRow && j == startCol) // as i am traversing backwards
                return 1;

            else
                return 0;
        }

        if(dp[i][j][moves] != -1.00)
        return dp[i][j][moves];

        double ans = 0.00;

        for (int k = 0; k < directions.size(); k++) {
            int prev_i = i - directions[k].first;
            int prev_j = j - directions[k].second;

            if (prev_i >= 0 && prev_i < N && prev_j >= 0 && prev_j < N) {
                ans += solve(prev_i, prev_j, moves - 1,dp) / 8;
            }
        }
        return  dp[i][j][moves] = ans;
    }

    double knightProbability(int n, int k, int row, int column) {
        startRow = row;
        startCol = column;
        N = n;

        vector<vector<vector<double>>> dp(n + 1,vector<vector<double>>(n + 1,vector<double>(k + 1,-1.00)));

        double probability = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                probability += solve(i, j, k,dp);
            }
        }

        return probability;
    }
};