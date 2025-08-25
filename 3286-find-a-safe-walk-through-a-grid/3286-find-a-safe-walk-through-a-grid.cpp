class Solution {
public:
    int row[4] = {1, -1, 0, 0};
    int col[4] = {0, 0, 1, -1};

    bool isValid(int i, int j, int m, int n) {
        return i >= 0 && j >= 0 && i < m && j < n;
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        int startHealth = health - grid[0][0];
        if (startHealth <= 0)
            return false;

        vector<vector<int>> visited(m, vector<int>(n, -1));
        visited[0][0] = startHealth;

        queue<pair<int, pair<int, int>>> q;
        q.push({0, {0, startHealth}});

        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second.first;
            int h = q.front().second.second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int new_i = i + row[k];
                int new_j = j + col[k];

                if (isValid(new_i, new_j, m, n)) {
                    int newHealth = h - grid[new_i][new_j];

                    if (newHealth > 0 && newHealth > visited[new_i][new_j]) {

                        if (new_i == m - 1 && new_j == n - 1 && h >= 1)
                        return true;

                        visited[new_i][new_j] = newHealth;
                        q.push({new_i, {new_j, newHealth}});
                    }
                }
            }
        }
        return false;
    }
};