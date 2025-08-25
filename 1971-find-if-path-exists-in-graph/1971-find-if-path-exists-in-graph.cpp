class Solution {
public:
    bool DFS(int source,vector<vector<int>>& adj,vector<bool>& visited,int destination){
        if(source == destination)return true;
        visited[source] = true;

        for(int i=0;i<adj[source].size();i++){
            if(!visited[adj[source][i]])
            {
                if(DFS(adj[source][i],adj,visited,destination))
                return true;
            }

        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination)
        return true;

        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n,false);


        // for(int i=0;i<n;i++){
            // if(!visited[i]){
                if(DFS(source,adj,visited,destination))
                return true;
            // }
        // }

        return false;
    }
};