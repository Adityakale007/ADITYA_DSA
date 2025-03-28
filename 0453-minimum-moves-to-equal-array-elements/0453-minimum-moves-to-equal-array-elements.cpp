class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int mini = nums[0];
        int sum = 0;
        
        for(int i=n-1;i>0;i--){
            int diff = nums[i] - mini;
            sum += diff;
        }
        return sum;
    }
};