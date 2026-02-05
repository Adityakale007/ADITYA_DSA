class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n,0);

        for(int i=0;i<n;i++)
        {
            if(nums[i] > 0){
                int k = (i + nums[i])%n;
                result[i] = nums[k];
            }
            else if(nums[i] < 0){
                int k = (n + i - (-1 * nums[i])%n)%n;
                result[i] = nums[k];
            }
        }
        return result;
    }
};