class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int n = nums.size();
        int peak = n-1;

        for(int i=0;i<n-1;i++)
        {
            if(nums[i] > nums[i+1]){
                peak = i;
                break;
            }
        }
        long long sumI = 0;
        long long sumD = 0;

        for(int i=0;i<=peak;i++){
            sumI += nums[i];
        }
        for(int i=peak;i<n;i++){
            sumD += nums[i];
        }

        if(sumI > sumD){
            return 0;
        }
        else if(sumI < sumD){
            return 1;
        }
        else
            return -1;
    }
};