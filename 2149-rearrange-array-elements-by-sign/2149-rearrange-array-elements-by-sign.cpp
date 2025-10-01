class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> numsPositive;
        vector<int> numsNegative;

        for(int i=0;i<n;i++){
            if(nums[i] > 0){
                numsPositive.push_back(nums[i]);
            }
            else{
                numsNegative.push_back(nums[i]);
            }
        }

        vector<int> ans;
        
        for(int i=0;i<n/2;i++){
            ans.push_back(numsPositive[i]);
            ans.push_back(numsNegative[i]);
        }

        return ans;
    }
};