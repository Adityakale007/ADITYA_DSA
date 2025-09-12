class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();

        if(n == 1)return false;
        
        for(int left = 0;left<n;left++){
            int right = left+1;
            while(right <= left + k && right<n){
                if(nums[left] == nums[right]){
                    return true;
                }
                right++;
            }
        }
        return false;

    }
};