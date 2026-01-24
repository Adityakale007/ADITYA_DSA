class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int sum = 0;
        int maxSum = 0;
        for(int i=0;i<n;i++){
            sum = nums[i] + nums[n - i - 1];
            maxSum = max(maxSum,sum);
        }

        return maxSum;
    }
};