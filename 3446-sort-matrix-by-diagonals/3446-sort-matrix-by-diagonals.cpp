class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // map: key = (i-j), value = elements along that diagonal
        map<int, vector<int>> diagonals;

        // Step 1: collect elements along each diagonal
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                diagonals[i - j].push_back(grid[i][j]);
            }
        }

        // Step 2: sort diagonals depending on position
        for (auto &d : diagonals) {
            if (d.first >= 0) {
                // on/above main diagonal → ascending
                sort(d.second.begin(), d.second.end());
                // store reversed so we can pop_back() later
            } else {
                // below main diagonal → descending
                sort(d.second.begin(), d.second.end(), greater<int>());
                // store reversed so we can pop_back() later
            }
        }

        // Step 3: put elements back into the matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = diagonals[i - j].back(); // take last element
                diagonals[i - j].pop_back();
            }
        }

        return grid;
    }
};