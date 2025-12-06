class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();

        int cnt = 0;
        int sumL = 0;

        for(int i=0;i<n-1;i++){
            sumL += nums[i];
            int sumR = 0;
            for(int j=i+1;j<n;j++){
                sumR += nums[j];
            }

            if((abs(sumL - sumR))%2 == 0){
                cnt++;
            }
        }
        return cnt;
    }
};