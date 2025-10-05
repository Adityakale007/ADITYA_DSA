class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        long long sum = 0;
        for(int i=0;i<nums.size();i++){
            ans = ans ^ nums[i];
            sum += nums[i];
        }
        if(sum == 0)return 0;
        if(ans == 0 && sum!=0)return n-1;
        return n;
    }
};