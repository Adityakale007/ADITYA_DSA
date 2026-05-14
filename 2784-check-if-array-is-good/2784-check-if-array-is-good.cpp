class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        if(n == 1)return false;
        if((n == 2 )  &&  ((nums[0] != nums[1])    ||  (nums[0] != 1)))return false;

        for(int i=0;i<n-1;i++){
            if(nums[i] != i+1){
                return false;
            }
        }
        if(nums[n-2] != nums[n-1])return false;

        return true;
    }
};