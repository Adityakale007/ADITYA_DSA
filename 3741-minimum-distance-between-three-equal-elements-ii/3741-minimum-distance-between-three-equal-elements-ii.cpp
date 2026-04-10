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
            // Since indices are sorted:
            // (j - i) + (k - j) + (k - i)
            // = (j - i + k - j) + (k - i)
            // = (k - i) + (k - i)
            // = 2 * (k - i)
            // So the middle index j does not matter at all.

            if(m.second.size() >= 3){
                int sum = INT_MAX;
                for(int i=0;i+2<m.second.size();i++){
                    sum = min(sum , abs(m.second[i+2] - m.second[i]));
                }
                ans = min(ans,sum);
            }
        }
        return ans != INT_MAX ? 2*ans : -1;
    }
};