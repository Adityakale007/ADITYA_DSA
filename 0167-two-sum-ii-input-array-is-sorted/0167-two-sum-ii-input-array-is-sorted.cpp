class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            int k = target - nums[i];
            if(m.find(k) != m.end()){
                return {m[k]+1,i+1};
            }
            m[nums[i]] = i;
        }
        return {-1,-1};
    }
};