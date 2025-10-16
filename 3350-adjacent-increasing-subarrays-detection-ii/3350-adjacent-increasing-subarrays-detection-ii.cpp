class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int cnt = 1;
        int prev_cnt = 0;
        int ans = 0;

        for(int i=1;i<n;i++){
            if(nums[i] > nums[i-1]){
                cnt++;
            }
            else{
                prev_cnt = cnt;
                cnt = 1;
            }

            ans = max(ans , min(cnt,prev_cnt));
            ans = max(ans , cnt/2);

        }
        return ans;
    }
};