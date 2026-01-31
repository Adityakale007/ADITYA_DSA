class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        //number of subarrays question using two pointer technique
        //same as leetcode question number 5 -> Subarrays With Sum Equals K
        int n = nums.size();
        int cnt = 0;

        //clasic prefixsum problem
        // unordered_map<int,int>m;
        // m[0] = 1;
        // int prefixSum = 0;
        // for(int i=0;i<n;i++){
        //     prefixSum += nums[i];

        //     int remove = prefixSum - goal;
        //     cnt += m[remove];   //map counts the number of occurrence of the element need to be removed

        //     m[prefixSum]++;
        // }




        //two pointers approach
        // int l = 0;
        // int r = 0;
        // int sum = 0;
        // while(r<n){
        //     sum += nums[r];

        //     if(sum > goal){
        //         sum -= nums[l];
        //         l++;
        //     }

        //     if(sum == goal)cnt++;

        //     r++;
        // }//////////here movement of left is ambigous

        //so we try pattern - 2
        //final cnt =>> (Subarrays With Sum <= K) - (Subarrays With Sum <= K - 1)
        //(Subarrays With Sum <= K) ->> is typically the length as an element itself is a subarray
        //O(2 x 2 x N) is the time complexity

        int l = 0;
        int r = 0;
        int cnt1 = 0;
        long long sum = 0;

        //for (Subarrays With Sum <= K)
        if (goal < 0)return 0;

        while(r<n){
            sum += nums[r];

            // if(sum > goal){
            //     sum -= nums[l];
            //     l++;
            // }        You must shrink until sum ≤ goal, not just once.
            while(sum > (goal)){
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
        if (goal - 1 < 0) return cnt1;

        while(r<n){
            sum += nums[r];

            // if(sum > (goal-1)){
            //     sum -= nums[l];
            //     l++;
            // }        You must shrink until sum ≤ goal-1, not just once.
            while(sum > (goal - 1)){
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