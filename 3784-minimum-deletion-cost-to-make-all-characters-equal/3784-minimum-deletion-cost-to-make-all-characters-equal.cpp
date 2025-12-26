class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        int n = cost.size();
        unordered_map<char,long long>mp;

        for(int i=0;i<n;i++){
            mp[s[i]] += cost[i];
        }
        if(mp.size() <= 1)return 0;

        long long sum = 0;
        for(auto m:mp){
            sum += m.second;
        }

        long long total = sum;
        long long ans = LLONG_MAX;
        for(auto m:mp){
            sum = total;
            sum -= m.second;
            if(sum < ans){
                ans = sum;
            }
        }
        return ans;
    }
};