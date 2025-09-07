class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> freq;

        for(int i=0;i<n;i++){
            if(freq.count(nums[i])){
                freq[nums[i]]++;
            }
            else{
                freq[nums[i]] = 1;
            }
        }

        if(freq.size() == 1)return 0;
    // as AND of whole array is 0
        return 1;
    }
};