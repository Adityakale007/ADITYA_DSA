class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        int n = nums.size();

        bool ans = false;
        unordered_map<int,int> freq;

        for(int i=0;i<n;i++){
            if(freq.count(nums[i])){
                freq[nums[i]]++;
            }
            else{
                freq[nums[i]] = 1;
            }
        }

        for(auto it:freq){
            if(it.second > 1){
                ans = true;
            }
        }

        return ans;
    }
};