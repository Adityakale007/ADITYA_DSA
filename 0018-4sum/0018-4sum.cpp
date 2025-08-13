class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> answer;

        for(int i=0;i<n-3;i++){
            if(i>0 && nums[i] == nums[i-1])continue;//skips duplicates  
            for(int j=i+1;j<n-2;j++){
                if(j>i+1 && nums[j] == nums[j-1])continue;//skips duplicates  
                for(int k=j+1;k<n-1;k++){
                    if(k>j+1 && nums[k] == nums[k-1])continue;//skips duplicates  
                    int m = k+1;
                    long long total = (long long)target - ((long long)nums[i]+nums[j]+nums[k]);
                    auto it = lower_bound(nums.begin() + m, nums.end(), (int)total);
                    if(it!=nums.end() && *it==total){
                        answer.push_back({nums[i],nums[j],nums[k],(int)total});
                    }
                }
            }
        }
        return answer;
    }
};