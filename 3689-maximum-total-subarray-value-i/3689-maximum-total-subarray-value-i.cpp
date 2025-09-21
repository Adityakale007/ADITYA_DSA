class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int maxi = INT_MIN;
        int mini = INT_MAX;

        int n = nums.size();

        for(int i=0;i<n;i++){
            if(nums[i] > maxi){
                maxi = nums[i];
            }
        }

        for(int i=0;i<n;i++){
            if(nums[i] < mini){
                mini = nums[i];
            }
        }

        long long ans = maxi - mini;

        return (long long)k*ans;

    }
};