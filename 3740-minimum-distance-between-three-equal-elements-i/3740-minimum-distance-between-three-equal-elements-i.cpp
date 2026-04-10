class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }

        int ans = INT_MAX;

        for(auto m:mp){
            if(m.second.size() >= 3){
                int sum = INT_MAX;
                for(int i=0;i+1<m.second.size();i++){
                    for(int j=i+1;j+1<m.second.size();j++){
                        sum = min(sum , abs(m.second[j] - m.second[i]) + abs(m.second[j+1] - m.second[i+1]) + abs(m.second[j+1] - m.second[i]));
                    }
                }
                ans = min(ans , sum);
            }
        }

        return ans != INT_MAX ? ans : -1;
    }
};