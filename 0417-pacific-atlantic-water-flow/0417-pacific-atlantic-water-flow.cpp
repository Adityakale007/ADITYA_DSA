class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        // Directions: up, down, left, right
        vector<pair<int,int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};

        auto dfs = [&](auto&& self, int r, int c, vector<vector<bool>>& visited) -> void {
            visited[r][c] = true;
            for(auto [dr,dc]: dirs){
                int nr = r + dr;
                int nc = c + dc;
                if(nr>=0 && nr<m && nc>=0 && nc<n && !visited[nr][nc] 
                   && heights[nr][nc] >= heights[r][c]){
                    self(self, nr, nc, visited);
                }
            }
        };

        // Start DFS from Pacific edges
        for(int i=0;i<m;i++){
            dfs(dfs, i, 0, pacific);
            dfs(dfs, i, n-1, atlantic);
        }
        for(int j=0;j<n;j++){
            dfs(dfs, 0, j, pacific);
            dfs(dfs, m-1, j, atlantic);
        }

        vector<vector<int>> result;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacific[i][j] && atlantic[i][j]){
                    result.push_back({i,j});
                }
            }
        }

        return result;
    }
};
