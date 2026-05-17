class Solution {
public:
    //solving dp like
    bool solve(vector<int>& arr, int start,vector<bool>& visited){
        int n = arr.size();

        //base case
        if(start >= n   ||  start<0)
            return false;

        if(arr[start] == 0)
            return true;

        if(visited[start])
            return false;   //cycle deteted
        
        //mark visited
        visited[start] = true;

        bool add = solve(arr,start + arr[start],visited);
        bool sub = solve(arr,start - arr[start],visited);

        return add || sub;
    }
    bool canReach(vector<int>& arr, int start) {
        //in this question we will be using a visited array to mark visited indexes to detect a cycle
        vector<bool> visited(arr.size(),false);
        return solve(arr,start,visited);
    }
};