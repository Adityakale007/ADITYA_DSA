class Solution {
public:
    void dfs(int node, vector<vector<int>>& isConnected,
             vector<bool>& visited) {
        visited[node] = true;
        // for (int neighbor : isConnected[node]) {
        //     if (!visited[neighbor]) {
        //         dfs(neighbor, isConnected, visited);
        //     }
        // }

        //as vector adj
        int V = isConnected.size();
        for (int j = 0; j < V; j++) {
            if (isConnected[node][j] == 1 && !visited[j]) {
                dfs(j, isConnected, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<bool> visited(V, false);

        int count = 0;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, isConnected, visited);
                count++;
            }
        }
        return count;
    }
};