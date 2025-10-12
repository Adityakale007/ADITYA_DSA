class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> freq;

        for(int num:nums){
            freq[num]++;
        }

        int sum = 0;

        for(auto &f:freq){
            if(f.second % k == 0){
                sum += (f.first * f.second);
            } 
        }

        return sum;
    }
};