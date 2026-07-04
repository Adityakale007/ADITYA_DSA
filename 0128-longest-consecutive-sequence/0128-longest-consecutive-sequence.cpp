class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        sort(nums.begin(),nums.end());
        int cnt = 1;
        int final_cnt = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i] == nums[i-1] + 1){
                cnt++;
                final_cnt = max(final_cnt , cnt);
            }
            else if(nums[i] == nums[i-1]){
                continue;
            }
            else{
                cnt = 1;
            }
        }
        return final_cnt;
    }
};