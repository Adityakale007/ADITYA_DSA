class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int maxIndex = 0;
        int mini = INT_MAX;
        int minIndex = 0;

        for(int i=0;i<n;i++){
            if(nums[i] > maxi){
                maxi = nums[i];
                maxIndex = i;
            }

            if(nums[i] < mini){
                mini = nums[i];
                minIndex = i;
            }
        }

        int ans = INT_MAX;
        int l = max(minIndex,maxIndex);
        int r = min(minIndex,maxIndex);

        //both at start
        ans = min(ans , l+1);

        //one at start other at end
        ans = min(ans , (r+1)+(n-l));

        //both at end
        ans = min(ans , n-r);

        return ans;
    }
};