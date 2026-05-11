class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        vector<int> ans = nums;
        int n = nums.size();
        reverse(ans.begin(),ans.end());
        for(int i=0;i<n;i++){
            nums.push_back(ans[i]);
        }
        return nums;
    }
};