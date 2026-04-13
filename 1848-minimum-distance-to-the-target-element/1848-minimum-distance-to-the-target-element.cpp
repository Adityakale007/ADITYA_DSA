class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }

        int mini = INT_MAX;
        for(int i=0;i<mp[target].size();i++){
            mini = min(mini,abs(start - mp[target][i]));
        }
        return mini;
    }
};