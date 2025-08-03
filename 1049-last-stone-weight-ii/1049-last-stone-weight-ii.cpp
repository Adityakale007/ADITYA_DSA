class Solution {
public:
    int solve(vector<int>& stones,int n,int index,int target,vector<vector<int>>& dp){
        //base case
        if(index>=n)
            return 0;
        if(target == 0)
            return target;

        if(dp[index][target] != -1)
            return dp[index][target];

        int include = 0;
        if(target >= stones[index])
            include = stones[index] + solve(stones,n,index+1,target-stones[index],dp);
        int exclude = 0 + solve(stones,n,index+1,target,dp);

        return dp[index][target] = max(include,exclude);
    }

    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += stones[i];
        }
        int target = sum/2;

        vector<vector<int>> dp(n+1 , vector<int> (target+1 , -1));

        int ans = solve(stones,n,0,target,dp);

        return sum - 2*ans;
    }
};