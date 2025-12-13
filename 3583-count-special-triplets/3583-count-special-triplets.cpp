class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        int ans = 0;

        unordered_map<long long, long long>rightFreq,leftFreq;

        for(int n:nums){
            rightFreq[n]++;
        }
        rightFreq[nums[0]]--;
        leftFreq[nums[0]]++;

        for(int i=1;i<n-1;i++){
            rightFreq[nums[i]]--;

            long long target = 2LL * nums[i];

            long long leftCount = leftFreq[target];
            long long rightCount = rightFreq[target];

            ans = (ans + leftCount * rightCount) % MOD;

            leftFreq[nums[i]]++;
        }

        return ans;
    }
};