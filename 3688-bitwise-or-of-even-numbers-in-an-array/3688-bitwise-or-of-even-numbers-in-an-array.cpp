class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int n=nums.size();
        vector<int> even;

        for(int i=0;i<n;i++){
            if(nums[i]%2 == 0)
            {
                even.push_back(nums[i]);
            }
        }

        if(even.size() == 0){
            return 0;
        }

        if(even.size() == 1){
            return even[0];
        }

        int ans=0;

        for(int i=0;i<even.size()-1;i++){
            ans = ans | even[i] | even[i+1];
        }
        return ans;
    }
};