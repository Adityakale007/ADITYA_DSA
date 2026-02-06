class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        //calculate max balanced array size
        //then subtract it from initial size
        int n = nums.size();
        int l = 0;
        int r = 0;
        int maxLength = 0;
        sort(nums.begin(),nums.end());
        while(r<n){
            while(1LL * nums[r] > (1LL * k * nums[l])){
                l++;
            }
            maxLength = max(maxLength , r-l+1);
            r++;
        }

        return n - maxLength;
    }
};