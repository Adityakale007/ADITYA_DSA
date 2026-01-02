class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int sum1 = 0;
        int sum2 = 0;

        for(int i=0;i<k;i++){
            sum1 += nums[i];
        }
        int l = n-k;
        for(int i=n-1;i>=l;i--){
            sum2 += nums[i];
        }

        return sum2 - sum1;
    }
};