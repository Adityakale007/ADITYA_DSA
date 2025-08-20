class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n);
        for(int i=0;i<dislikes.size();i++){
            int u = dislikes[i][0] -1;
            int v = dislikes[i][1] -1;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int>color(n,-1);
        queue<int> q;

        for(int i=0;i<n;i++){
            if(color[i] == -1){
                q.push(i);
                color[i] = 0;

                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    
                    for(int i=0;i<adj[node].size();i++){
                        //if not colored
                        if(color[adj[node][i]] == -1){
                            color[adj[node][i]] = (color[node] + 1)%2;
                            q.push(adj[node][i]);
                        }
                        //if colored
                        else{
                            if(color[adj[node][i]] == color[node])
                                return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};