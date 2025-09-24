// Tarjan's algorithm.
// findiing BRIDGES

class Solution {
public:


    void DFS(int node,int parent,vector<vector<int>> &adj,vector<int> &disc,vector<int> &low,vector<bool> &visited,vector<vector<int>> &bridges,int &count){

        disc[node] = low[node] = count;
        visited[node] = 1;

        for(int j=0;j<adj[node].size();j++){
            
            int neighbour = adj[node][j];

            if(neighbour == parent){
                continue;
            }
            else if(visited[neighbour]){
                low[node] = min(low[node],low[neighbour]);
            }
            else{

                count++;
                DFS(neighbour,node,adj,disc,low,visited,bridges,count);

                if(disc[node] < low[neighbour]){
                    vector<int> temp;
                    temp.push_back(node);
                    temp.push_back(neighbour);

                    bridges.push_back(temp);
                }

                low[node] = min(low[node],low[neighbour]);
            }

        }
    }


    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
         vector<vector<int>>adj(n);
         for(int i=0;i<connections.size();i++){
            int u = connections[i][0];
            int v = connections[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
         }

        vector<vector<int>> bridges;
        vector<int> disc(n);
        vector<int> low(n);

        vector<bool> visited(n);

        int count = 0;
        DFS(0,-1,adj,disc,low,visited,bridges,count);

        return bridges;
    }
};