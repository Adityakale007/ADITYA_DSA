class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
    
        vector<int> b;
       sort(nums.begin(),nums.end());
       for(int i=0;i<n;i++){
        if(i+1 >= nums.size()) break;
        if (nums[i]==nums[i+1]){
            b.push_back(nums[i]);

        }
        
       }
       return b;
    }
};