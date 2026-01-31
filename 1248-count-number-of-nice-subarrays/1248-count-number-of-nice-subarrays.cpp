class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        //similar to
        //930. Binary Subarrays With Sum
        //just here consider all odd as 1 and all even as 0 and we need to find the number of subarrays equating their sum to k

        int n = nums.size();
        //converting to binary array
        for(int i=0;i<n;i++){
            nums[i] = (nums[i]%2);
        }

        //code 
        int cnt = 0;
        int l = 0;
        int r = 0;
        int cnt1 = 0;
        long long sum = 0;

        //for (Subarrays With Sum <= K)
        if (k < 0)return 0;

        while(r<n){
            sum += nums[r];

            // if(sum > k){
            //     sum -= nums[l];
            //     l++;
            // }        You must shrink until sum ≤ k, not just once.
            while(sum > (k)){
                sum -= nums[l];
                l++;
            }
            cnt1 += (r-l+1);
            r++;
        }

        int cnt2 = 0;
        l = 0;
        r = 0;
        sum = 0;

        //for (Subarrays With Sum <= K-1)
        if (k - 1 < 0) return cnt1;

        while(r<n){
            sum += nums[r];

            // if(sum > (k-1)){
            //     sum -= nums[l];
            //     l++;
            // }        You must shrink until sum ≤ k-1, not just once.
            while(sum > (k - 1)){
                sum -= nums[l];
                l++;
            }
            cnt2 += (r-l+1);
            r++;
        }

        cnt = cnt1 - cnt2;

        return cnt;
    }
};