class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();

        vector<int>left(n);
        vector<int>right(n);

        vector<int>ans(n);
        int leftSum = 0;
        int rightSum = 0;

        for(int i=0;i<n;i++){
            left[i] = leftSum;
            leftSum+=nums[i];
        }
        for(int i=n-1;i>=0;i--){
            right[i] = rightSum;
            rightSum+=nums[i];
        }

        for(int i=0;i<n;i++){
            ans[i] = abs(left[i] - right[i]);
        }

        return ans;
    }
};