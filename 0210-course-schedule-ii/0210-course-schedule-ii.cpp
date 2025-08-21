class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];

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
        vector<int> answer;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            answer.push_back(node);

            for(int i=0;i<adj[node].size();i++){
                inDegree[adj[node][i]]--;
                if(inDegree[adj[node][i]] == 0){
                    q.push(adj[node][i]);
                }
            }
        }
        vector<int>emptyArray;
        return answer.size() == numCourses ? answer :   emptyArray;
    }
};