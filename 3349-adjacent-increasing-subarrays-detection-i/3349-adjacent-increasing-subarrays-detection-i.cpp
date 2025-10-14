class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2 * k) return false;
        vector<bool>inc(n-1,false);

        for(int i=0;i<n-1;i++){
            if(nums[i] < nums[i+1]){
                inc[i] = true;
            }
        }
        int full_length = 2*k - 1;//length of increasings

        for(int i = 0 ; i + 2*k  <= n ; i++){
            bool flag = true;

            for(int j=i;j< i + k - 1;j++){
                if(nums[j] >= nums[j+1])flag = false;
            }

            for(int j=i+k;j< i + 2*k - 1;j++){
                if(nums[j] >= nums[j+1])flag = false;
            }
            if(flag == true)return true;
        }
        
        return false;
    }
};