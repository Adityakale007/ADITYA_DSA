class Solution {
public:
    int maxTurbulenceSize(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1; 

        int maxLength = 1;
        int l = 0;
        int r = 1;
        bool flag = true;   //increase
            if(nums[l] == nums[r]){
                l = 1;
            }
            else{
                flag = nums[l] < nums[r];
                maxLength = 2;
            }

        while(r<n-1){
            if(nums[r] == nums[r+1]){
                l = r+1;
            }
            else if(flag && nums[r] > nums[r+1]){
                flag = false;
            }
            else if(!flag && nums[r] < nums[r+1]){
                flag = true;
            }
            else{
                l = r;
                flag = (nums[l] < nums[r+1]);
            }
            maxLength = max(maxLength , r-l+2);
            r++;
        }

        return maxLength;
    }
};