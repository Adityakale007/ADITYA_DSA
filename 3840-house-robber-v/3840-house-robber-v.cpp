class Solution {
public:
    vector<vector<long long>>dp;
    int n;

    long long rec(int i,int taken,vector<int>& nums, vector<int>& colors){
        if(i == n)return 0;
        long long ans = 0;

        if(dp[i][taken] != -1)
            return dp[i][taken];

        //not take
        ans = rec(i+1,0,nums,colors);

        //take
        if(taken == 0   ||  (i > 0  &&  colors[i] != colors[i-1])){
            ans = max(ans , nums[i]+rec(i+1,1,nums,colors));
        }

        return dp[i][taken] = ans;
    }
    
    long long rob(vector<int>& nums, vector<int>& colors) {
        n = colors.size();
        // long long ans = 0;

        // for(int i=0;i<n;i++){
        //     if(i>0 && (colors[i] == colors[i-1])){
        //         ans += max(nums[i],nums[i-1]);
        //     }
        //     else{
        //         ans += nums[i];
        //     }
        // }


        // return ans;
        dp.assign(n,vector<long long>(2,-1));
        return rec(0,0,nums,colors);
    }
};