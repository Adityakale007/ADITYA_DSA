class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        long long n = nums.size();
        long long m = target.size();
        sort(nums.begin(),nums.end());
        sort(target.begin(),target.end());

        vector<int> nums_EVEN;
        vector<int> nums_ODD;
        vector<int> target_EVEN;
        vector<int> target_ODD;

        //for nums
        for(int i=0;i<n;i++){
            if(nums[i]%2 != 0)
                nums_ODD.push_back(nums[i]);
            else
                nums_EVEN.push_back(nums[i]);
        }

        //for target
        for(int i=0;i<m;i++){
            if(target[i]%2 != 0)
                target_ODD.push_back(target[i]);
            else
                target_EVEN.push_back(target[i]);
        }

        long long diff = 0;
        for(int i=0;i<nums_EVEN.size();i++){
            diff += abs(nums_EVEN[i] - target_EVEN[i]);
        }
        for(int i=0;i<nums_ODD.size();i++){
            diff += abs(nums_ODD[i] - target_ODD[i]);
        }
        
        return diff/4;
    }
};