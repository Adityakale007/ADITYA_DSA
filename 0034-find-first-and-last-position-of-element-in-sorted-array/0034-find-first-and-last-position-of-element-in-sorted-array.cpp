class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int x=-1;
        int y=-1;
        for(int i = 0;i<nums.size();i++){
            if(target == nums[i]){
                x=i;
                break;
            }
        }
        for(int i = 0;i<nums.size();i++){
            if(target == nums[i]){
                y=i;
                
            }
        }
        return {x,y};
    }
};