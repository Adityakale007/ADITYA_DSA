class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        if(k <= 1)return 0;

        int mini = INT_MAX;

        int r = k-1;
        int l=0;

        while(r<n){
            int low = INT_MAX;
            int high = INT_MIN;
            for(int i=l;i<=r;i++){
                high = max(high,nums[i]);
                low = min(low,nums[i]);
            }
            mini = min(mini , high-low);

            l++;
            r++;
        }
        return mini;
    }
};