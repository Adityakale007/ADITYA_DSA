class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        //create a window
        double sum=0;
        for(int i=0;i<k;i++){
            sum += nums[i];
        }

        double maxSum = sum;

        //making windoew iterate
        for(int i=k ; i<n ; i++){
            sum += nums[i]; //adding new element
            sum -= nums[i-k]; //removing new element
            maxSum = max(sum,maxSum);
        }
        double ans = maxSum/k;
        return ans;
    }
};