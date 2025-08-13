class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i] == nums[i-1])continue;//skips duplicates  
            for(int j=i+1 ;j<n-1;j++){
                if(j>i+1 && nums[j] == nums[j-1])continue;//skips duplicates  
                
                int k=j+1;
                int target = -(nums[i] + nums[j]);
                auto it = lower_bound(nums.begin()+k , nums.end(),target);
                if(it!=nums.end() && target == *it)
                    answer.push_back({nums[i],nums[j],target});
            }
        }
        return answer;
    }
};