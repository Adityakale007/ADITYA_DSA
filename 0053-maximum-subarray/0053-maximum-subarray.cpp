class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int currSum = nums[0];
        int maxSum = nums[0];

        for(int i=1;i<n;i++){
            //KADANE's ALGORITHM
            //if currSum + nums[i] > currSum    -->     extend
            //if currSum + nums[i] < currSum    -->     start new subarray from nums[i]
            currSum = max(nums[i] , currSum + nums[i]);
            maxSum = max(maxSum , currSum);
        }
        return maxSum;
    }
};