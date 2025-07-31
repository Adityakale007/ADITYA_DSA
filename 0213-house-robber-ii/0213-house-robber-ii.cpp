//maximum sum of non-adjecent elements
class Solution {
    private:
    int solve_TOP_DOWN(vector<int>& nums,int n,vector<int>& dp){
        //base case
        if(n<0)return 0;
        if(n==0)return nums[0];

        if(dp[n] != -1){
            return dp[n];
        }

        int include = solve_TOP_DOWN(nums,n-2,dp) + nums[n];
        int exclude = solve_TOP_DOWN(nums,n-1,dp) + 0;
        dp[n] = max(include,exclude);

        return dp[n];
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n==1)return nums[0];

        vector<int> first;
        vector<int> second;
        for(int i = 0;i<n;i++){
            if(i != n-1){
               first.push_back(nums[i]); 
            }
            if(i!=0){
               second.push_back(nums[i]); 

            }
        }
        vector<int> dp1(first.size() + 1,-1);
        vector<int> dp2(second.size() + 1,-1);
        return max(solve_TOP_DOWN(first,first.size() - 1,dp1),
        solve_TOP_DOWN(second,second.size() - 1,dp2));
    }
};