class Solution {
public:

    vector<int> productExceptSelf(vector<int>& nums) {
        int MOD = 12345;

        int n = nums.size();
        vector<int> v(n,1);

        //prefix sum
        long long left = 1;
        for(int i = 0;i<n;i++){
            v[i] = left;
            left = (left * nums[i])%MOD;
        }

        //suffix sum
        long long right = 1;
        for(int i = n-1;i>=0;i--){
            v[i] = (1LL * v[i] * right)%MOD;
            right = (right * nums[i])%MOD;
        }
        return v;
    }


    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int MOD = 12345;

        vector<int> temp;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                temp.push_back(grid[i][j]);
            }
        }

        vector<int> answer = productExceptSelf(temp);
        vector<vector<int>> ans;

        for(int i=0;i<(n*m);i+=m){
            vector<int>temp2(answer.begin() + i,answer.begin() + i + m);
            ans.push_back(temp2);
        }

        return ans;
    }
};