class Solution {
public:
    bool isIncreasing(vector<int>& nums){
        int n = nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1])
                return false;
        }
        return true;
    }
    int minimumPairRemoval(vector<int>& nums){
        // int n = nums.size();
        int ans = 0;

        while(!isIncreasing(nums)){
            int index = -1;
            int minSum = INT_MAX;
            for(int i=0;i<nums.size()-1;i++){
                int sum = nums[i] + nums[i+1];

                if(sum < minSum){
                    minSum = sum;
                    index = i;
                }
            }

            nums[index] = minSum;
            nums.erase(nums.begin() + index + 1);
            ans++;
        }

        return ans;
    }
};