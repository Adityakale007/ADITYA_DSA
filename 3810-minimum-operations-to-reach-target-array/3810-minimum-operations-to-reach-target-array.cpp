class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        int cnt = 0;
        unordered_map<int,int>m;
        vector<int>v;
        for(int i=0;i<n;i++){
            if(nums[i] != target[i])v.push_back(nums[i]);
        }
        for(int i=0;i<v.size();i++){
            m[v[i]]++;
        }
        return m.size();
    }
};