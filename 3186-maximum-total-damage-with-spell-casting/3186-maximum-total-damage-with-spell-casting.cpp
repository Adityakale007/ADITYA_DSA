class Solution {
public:
    long long solveTopDown(int i,vector<long long>& dmg,vector<long long>& total,vector<long long>& dp){
        int n = (int)dmg.size();
        if(i>=n)return 0;

        if(dp[i] != -1){
            return dp[i];
        }

        long long notTake = solveTopDown(i+1,dmg,total,dp);
        long long take = total[i];

        int nextIndex = lower_bound(dmg.begin(),dmg.end(),dmg[i] + 3) - dmg.begin();
        take += solveTopDown(nextIndex,dmg,total,dp);

        return dp[i] = max(take,notTake);
    }

    long long maximumTotalDamage(vector<int>& power) {
        sort(power.begin(),power.end());

        unordered_map<long long,long long> sum;
        for(int i:power) sum[i] += i;

        vector<long long> dmg;
        vector<long long> total;

        for(auto &it:sum){
            dmg.push_back(it.first);
        }
        sort(dmg.begin(),dmg.end());
        for(auto d:dmg){
            total.push_back(sum[d]);
        }

        vector<long long>dp(dmg.size() , -1);
        return solveTopDown(0,dmg,total,dp);
    }
};