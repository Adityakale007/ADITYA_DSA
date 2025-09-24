class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin(),nums.end(),greater<int>());

        unordered_set<int> seen;
        vector<int> result;

        for(int x:nums){
            if(seen.find(x) == seen.end()){
                seen.insert(x);
                result.push_back(x);
            }
        }

        n = result.size();

        if(n>=k){
            vector<int> ans(result.begin(),result.begin()+k);
            return ans;
        }
        else{
            return result;
        }

        return {};
    }
};