class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        long long n = nums.size();
        long long cnt = 0;

        for(int i = 0;i<(int)nums.size();i++){
            nums[i] = abs(nums[i]);
        }
        sort(nums.begin(),nums.end());

        for(long long j=0;j<n;j++){
            int a = nums[j];
            int target = (int)ceil((double)a/2); // for ceil

            int index = lower_bound(nums.begin(),nums.begin()+j,target) - nums.begin();

            cnt = cnt + (j - index); 
        }
        return cnt;
    }
};