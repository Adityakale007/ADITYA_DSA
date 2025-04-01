class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int diff = 0;
        int ans = 0;
        for(int i = 0;i<n-1;i++){
            diff = (nums[i+1] - nums[i]);
            ans = max(ans,diff);
        }
        return ans;
    }
};