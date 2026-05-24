class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        int cnt = 0;
        unordered_set<int>st;
        for(int i=0;i<n;i++){
            if(!st.count(nums[i])){
                st.insert(nums[i]);
                cnt = 0;
                ans.push_back(nums[i]);
                cnt++;
            }
            else{
                cnt++;
                if(cnt <= k){
                    ans.push_back(nums[i]);
                }
            }
        }
        return ans;
    }
};