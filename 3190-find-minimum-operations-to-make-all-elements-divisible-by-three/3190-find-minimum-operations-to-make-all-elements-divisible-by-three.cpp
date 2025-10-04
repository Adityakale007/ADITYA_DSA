class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            if(nums[i] % 3 != 0){
                nums[i] = nums[i]%3;
                sum ++;
            }
        }
        return sum;
    }
};