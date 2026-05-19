class Solution {
public:
    // int solve(vector<int> &nums,int index,unordered_map<int,vector<int>>& mp,vector<bool> &visited,vector<int> &dp){
    //     int n = nums.size();

    //     //base case
    //     if(index >= n   ||  index < 0)
    //         return INT_MAX; 
        
    //     if(index == n-1)
    //         return 0;


    //     if(dp[index] != -1)
    //         return dp[index];

    //     // prevent cycles
    //     if(visited[index])
    //         return INT_MAX;

    //     visited[index] = true;

        
    //     int ans = INT_MAX;

    //     //three posibilites
        
    //     //move right
    //     int a = solve(nums,index + 1,mp,visited,dp);
    //     // if(index + 1 < n)    //already base case
    //     if(a != INT_MAX)
    //         ans = min(ans , 1 + a);
        
    //     //move left
    //     int b = solve(nums,index - 1,mp,visited,dp);
    //     // if(index - 1 >= 0)    //already base case
    //     if(b != INT_MAX)
    //         ans = min(ans , 1 + b);
        
        
    //     for(auto newIndex : mp[nums[index]]){
    //         if(newIndex != index){
    //             int c = solve(nums,newIndex,mp,visited,dp);

    //             if(c != INT_MAX){
    //                 ans = min(ans , 1 + c);
    //             }
    //         }
    //     }
    //     return dp[index] = ans;
    // }


            // Dynamic programming on graphs usually requires a topological ordering.
            // A topological ordering exists only in acyclic graphs (DAGs).
            // Back edges create cycles in the graph.
            // Therefore, standard DAG-based DP cannot be applied directly.
            // However, DP can still be used with more complex methods, though it may be less efficient.


            // Correct Idea → BFS
            // Think of every index as a graph node.
            // From index i you can go to:
            // i+1
            // i-1
            // every index having same value
            // Since every edge cost = 1,
            // minimum steps = shortest path in unweighted graph → BFS.


    int minJumps(vector<int>& nums) {
        int n = nums.size();
        // unordered_map<int,vector<int>>mp;
        // for(int i=0;i<n;i++){
        //     mp[nums[i]].push_back(i);
        // }   
        // vector<int> dp(n,-1);
        // vector<bool> visited(n, false);
        // return solve(nums,0,mp,visited,dp);
    
        if(n == 1)
            return 0;
        

        //using BFS
        unordered_map<int,vector<int>>mp;
        vector<int> visited(n,false);
        queue<int>q;
        int steps = 0;

        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }

        q.push(0);  //first index
        visited[0] = true;

        while(!q.empty()){
            int size = q.size();

            while(size--){
                int index = q.front();
                q.pop();

                if(index == n-1)
                    return steps;
                

                //move right
                if(index + 1 < n   &&   !visited[index + 1]){
                    visited[index + 1] = true;
                    q.push(index + 1);
                }

                //move left
                if(index - 1 >= 0   &&   !visited[index - 1]){
                    visited[index - 1] = true;
                    q.push(index - 1);
                }

                //push identicles
                for(auto newIndex : mp[nums[index]]){
                    if(!visited[newIndex]){
                        visited[newIndex] = true;
                        q.push(newIndex);
                    }
                }
                mp[nums[index]].clear(); // <-- optimization step
                //as every element is added in the queue
            }
            steps++;
        }
        return steps;
    }
};