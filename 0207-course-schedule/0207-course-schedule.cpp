class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[u].push_back(v);
        }

        //applying KAHN's ALGORITHM
        vector<int> inDegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(int j=0;j<adj[i].size();j++){
                inDegree[adj[i][j]]++;
            }
        }

        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(inDegree[i] == 0)
                q.push(i);
        }
        int count = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;

            for(int i=0;i<adj[node].size();i++){
                inDegree[adj[node][i]]--;
                if(inDegree[adj[node][i]] == 0){
                    q.push(adj[node][i]);
                }
            }
        }
        return count == numCourses;
    }
};