class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        // considering constraints using brute force of n2 complexity
        int n = nums.size();
        unordered_map<int,int>mp;
        int ans = 0;

        for(int i=0;i<n;i++){
            mp.clear();
            for(int j=i;j<n;j++){
                mp[nums[j]]++;
                if(mp[target] > (0.5 * (j-i+1)))ans++;
            }
        }
        return ans;
    }
};