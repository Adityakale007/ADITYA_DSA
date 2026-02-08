class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        int n = nums.size();
        vector<long long>ans;

        for(int i=0;i<n;i++){
            ans.push_back(nums[i]);

            while(ans.size() >= 2 && ans.back() == ans[ans.size() - 2]){
                long long val = ans.back();
                ans.pop_back();
                ans.back() += val;
            }
        }

        return ans;
    }
};