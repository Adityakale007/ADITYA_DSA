class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();

        int cnt = 0;
        int sumL = 0;
        int sumR = 0;
        int totalSum = 0;

        for(int i=0;i<n ;i++){
            totalSum += nums[i];
        }

        for(int i=0;i<n-1;i++){
            sumL += nums[i];
            sumR = totalSum - sumL;

            if((abs(sumL - sumR))%2 == 0){
                cnt++;
            }
        }

        return cnt;
    }
};