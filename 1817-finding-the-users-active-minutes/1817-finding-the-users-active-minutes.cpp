class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        int n = logs.size();
        unordered_map<int,set<int>> mp;
        for(int i=0;i<n;i++){
            mp[logs[i][0]].insert(logs[i][1]);
        }

        vector<int>ans(k,0);

        for(auto &p:mp){
            int n = p.second.size();
            ans[n-1]++;
        }

        return ans;
    }
};