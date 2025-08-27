class Solution {
public:
    void DFS(int node , int dest ,vector<vector<int>>& graph , vector<bool>& visited,vector<int>& path , vector<vector<int>>& finalPath){

        path.push_back(node);

        if(node == dest){
            finalPath.push_back(path);
        }
        else{
            visited[node] = true;

            for(int j=0;j<graph[node].size();j++){
                if(!visited[graph[node][j]]){
                    DFS(graph[node][j],dest,graph,visited,path,finalPath);
                }
            }

            visited[node] = false;

        }

        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();


        vector<bool> visited(n,false);
        vector<int>path;
        vector<vector<int>>finalPath;
        DFS(0,n-1,graph,visited,path,finalPath);

        return finalPath;
    }
};