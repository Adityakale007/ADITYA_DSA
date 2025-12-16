class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        // 0 = empty
        // 1 = wall
        // 2 = guard
        // 3 = guarded
        vector<vector<int>> grid(m, vector<int>(n, 0));

        for (auto& w : walls)
            grid[w[0]][w[1]] = 1;

        for (auto& g : guards)
            grid[g[0]][g[1]] = 2;

        // Directions: up, down, left, right
        int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

        for (auto& g : guards) {
            int r = g[0], c = g[1];

            for (auto& d : dir) {
                int nr = r + d[0];
                int nc = c + d[1];

                while (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    if (grid[nr][nc] == 1 || grid[nr][nc] == 2) 
                        break; // blocked by wall or another guard
                    if (grid[nr][nc] == 0)
                        grid[nr][nc] = 3; // mark guarded

                    nr += d[0];
                    nc += d[1];
                }
            }
        }

        // Count unguarded empty cells
        int ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 0) ans++;

        return ans;
    }
};
