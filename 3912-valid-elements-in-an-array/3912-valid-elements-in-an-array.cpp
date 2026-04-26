class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        ans.push_back(nums[0]);
        
        vector<int>prefixMax(n);
        prefixMax[0] = INT_MIN;
        for(int i=1;i<n;i++){
            prefixMax[i] = max(prefixMax[i-1] , nums[i-1]);
        }
        vector<int>suffixMax(n);
        suffixMax[n-1] = INT_MIN;
        for(int i=n-2;i>=0;i--){
            suffixMax[i] = max(suffixMax[i+1] , nums[i+1]);
        }

        for(int i=1;i<n-1;i++){
            if(nums[i] > prefixMax[i]  ||  nums[i] > suffixMax[i]){
                ans.push_back(nums[i]);
            }
        }
        
        if(n > 1)ans.push_back(nums[n-1]);
        return ans;
    }
};