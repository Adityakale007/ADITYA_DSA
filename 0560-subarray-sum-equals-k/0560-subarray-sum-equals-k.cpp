class Solution {
public:

    int subarraySum(vector<int>& nums, int k) {

        int n = nums.size();
        int cnt = 0;
        //brute force -> form all posible subarrays ==>> O(N2)
        // for(int i=0;i<n;i++){
        //     int sum = 0;
        //     for(int j=i;j<n;j++){
        //         sum += nums[j];
        //         if(sum == k)cnt++;
        //     }
        // }

        //use PREFIXSUM
        //watch -> https://www.youtube.com/watch?v=xvNwoz-ufXA
        //we need to find prefix sum - k => how many subarrays(initial prefix sums that can be removed) are there given by cnt


        unordered_map<int,int>m;
        m[0] = 1;   //mandatory as if prefixSum-k is zero then map should return 1(occurred once)
        int prefixSum = 0;
        for(int i=0;i<n;i++){
            prefixSum += nums[i];

            int remove = prefixSum - k;
            cnt += m[remove];

            m[prefixSum]++;
        }

        return cnt;
    }
};