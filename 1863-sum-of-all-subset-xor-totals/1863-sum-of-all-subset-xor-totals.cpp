class Solution {
public:
    int rec(vector<int>& nums,int i,int ans){
        int n = nums.size();

        if(i==n)return ans;

        int take = rec(nums,i+1,ans^nums[i]);
        int notTake = rec(nums,i+1,ans);

        return take + notTake;
    }

    int subsetXORSum(vector<int>& nums) {
        return rec(nums,0,0);
    }
};