class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int n = nums.size();

        vector<long long>prefixSum(n);
        long long sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            prefixSum[i] = sum;
        }

        vector<long long>suffixMIN(n);
        long long mini = LLONG_MAX;
        for(int i=n-1;i>=0;i--){
            mini = min(mini,(long long)nums[i]);
            suffixMIN[i] = mini;
        }

        long long score = LLONG_MIN;
        long long ans = score;

        for(int i=0;i<n-1;i++){
            score = prefixSum[i] - suffixMIN[i+1];
            ans = max(ans,score);
        }
        return ans;
    }
};