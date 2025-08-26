class Solution {
public:
    vector<int> topoSort(int V, vector<vector<int>>& adj) {
        // code here

        vector<int> answer;
        vector<int> inDegree(V, 0);

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < adj[i].size(); j++) {
                inDegree[adj[i][j]]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (inDegree[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            answer.push_back(node);

            for (int j = 0; j < adj[node].size(); j++) {
                inDegree[adj[node][j]]--;
                if (inDegree[adj[node][j]] == 0)
                    q.push(adj[node][j]);
            }
        }
        vector<int> temp;
        return answer.size() == V    ?   answer     :       temp;
    }


    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions,
                                    vector<vector<int>>& colConditions) {

        vector<vector<int>> adj_row(k);
        vector<vector<int>> adj_col(k);

        for (int i = 0; i < rowConditions.size(); i++) {
            adj_row[rowConditions[i][1] - 1].push_back(rowConditions[i][0] - 1);
        }

        for (int i = 0; i < colConditions.size(); i++) {
            adj_col[colConditions[i][0] - 1].push_back(colConditions[i][1] - 1);
        }

        vector<int> order_of_row = topoSort(k,adj_row);
        vector<int> order_of_col = topoSort(k,adj_col);

        reverse(order_of_row.begin(),order_of_row.end());

        if (order_of_row.empty() || order_of_col.empty()) return {};

        vector<vector<int>> result(k, vector<int>(k, 0));
        unordered_map<int, int> rowMap, colMap;
        for (int i = 0; i < k; ++i) {
            rowMap[order_of_row[i]] = i;
            colMap[order_of_col[i]] = i;
        }
        
        for (int i = 1; i <= k; ++i) {
            result[rowMap[i - 1]][colMap[i - 1]] = i;
        }

        return result;

    }
};