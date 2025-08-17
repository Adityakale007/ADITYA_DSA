class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int mod = 1e9 + 7;
        int n = nums.size();
        int idx = 0;
        int ans = 0;

        for(int i=0;i<queries.size();i++){
            idx = queries[i][0];

            while(idx <= queries[i][1]){
                nums[idx] = (1LL*nums[idx] * queries[i][3]) % mod;
                idx += queries[i][2];
            }
        }
        //XOR of all element after all queries
        for(int i=0;i<n;i++){
           ans ^= nums[i];
        }
        return ans;
    }
};