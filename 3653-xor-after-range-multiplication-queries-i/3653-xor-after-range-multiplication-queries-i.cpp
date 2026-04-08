class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& q) {
        const int MOD = 1e9 + 7;
        int n = q.size();
        for(int i=0;i<n;i++){
            int index = q[i][0];
            while(index <= q[i][1]){
                nums[index] = (nums[index] * q[i][3]) % MOD;
                index += q[i][2];
            }
        }

        int ans = 0;
        for(int i=0;i<nums.size();i++){
            ans ^= nums[i];
        }
        return ans;
    }
};