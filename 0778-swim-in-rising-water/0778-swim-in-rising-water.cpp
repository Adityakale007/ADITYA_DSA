#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0});  // {time, row, col}

        vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        int ans = 0;

        while(!pq.empty()) {
            auto top = pq.top(); pq.pop();
            int t = top[0], r = top[1], c = top[2];

            ans = max(ans, t);
            if(r == n-1 && c == n-1) return ans;

            if(visited[r][c]) continue;
            visited[r][c] = true;

            for(auto [dr, dc] : dirs) {
                int nr = r + dr, nc = c + dc;
                if(nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]) {
                    pq.push({grid[nr][nc], nr, nc});
                }
            }
        }
        return ans;
    }
};
