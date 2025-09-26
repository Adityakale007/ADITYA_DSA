class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        long long sum = 0;
        for(int i=0;i<n-1;i++){
            sum += nums[i];
        }

        for(int i=n-1;i>=1;i--){
            if(nums[i] < sum){
                return nums[i] + sum;
            }
            else{
                sum -= nums[i-1];
            }
        }
        return (long long)-1;
    }
};

//1 1 2 3 5 12 50 