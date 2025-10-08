class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        int n = nums.size();

        for(int i=0;i<n;i++){
            int temp = nums[i];
            int ans = 0;
            while(temp>0){
                int diff = temp % 10;
                ans  = ans*10 + diff;
                temp /= 10;
            }
            nums.push_back(ans);
        }

        unordered_map<int,int>freq;
        for(int num:nums){
            freq[num]++;
        }
        return freq.size();
    }
};