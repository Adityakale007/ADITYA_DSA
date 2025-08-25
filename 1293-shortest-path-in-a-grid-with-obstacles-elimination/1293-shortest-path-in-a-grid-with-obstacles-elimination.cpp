class Solution {
public:
    int row[4] = {1, -1, 0, 0};
    int col[4] = {0, 0, 1, -1};

    bool isValid(int i, int j, int m, int n) {
        return i >= 0 && j >= 0 && i < m && j < n;
    }

    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        if(n==1 && m==1){
            if(k==0 && grid[0][0])
                return -1;
            
            if(!grid[0][0])
                return 0;
        }

        int start_K = k - grid[0][0];

        vector<vector<int>> visited(m, vector<int>(n, -1));
        visited[0][0] = start_K;

        queue<pair<int, pair<int, int>>> q;
        q.push({0, {0, start_K}});

        int step = 0;

        while (!q.empty()) {
            int count = q.size();

            while(count--){
                int i = q.front().first;
                int j = q.front().second.first;
                int fetch_K = q.front().second.second;
                q.pop();

                for (int t = 0; t < 4; t++) {
                    int new_i = i + row[t];
                    int new_j = j + col[t];

                    if (isValid(new_i, new_j, m, n)) {
                        int new_K = fetch_K - grid[new_i][new_j];

                        if (new_K > visited[new_i][new_j]) {

                            if (new_i == m - 1 && new_j == n - 1 && fetch_K >= 0)
                            return step+1;

                            visited[new_i][new_j] = new_K;
                            q.push({new_i, {new_j, new_K}});
                        }
                    }
                }
            }
            step++;
        }
        return -1;
    }
};