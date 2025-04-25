class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i = 0;
        int cnt = 0;
        for(i=0;i<nums.size();i++){
            if(nums[i]==nums[i+1]){
                cnt++;
                break;
            }
        }
        return nums[i];
    }
};