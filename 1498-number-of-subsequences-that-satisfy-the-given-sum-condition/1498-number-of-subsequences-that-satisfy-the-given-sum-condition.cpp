class Solution {
public:
    int mod = 1e9 + 7;
    int numSubseq(vector<int>& nums, int target) {
        //Hints:
        //sort the array
        //Use two pointers approach: Given an index i (choose it as the minimum in a subsequence) find the maximum j where j ≥ i and nums[i] +nums[j] ≤ target. 
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int l = 0;
        int r = n-1;
        int ans = 0;

        // Precompute powers of 2 modulo mod
        vector<int> power2(n);
        power2[0] = 1;
        for(int i=1;i<n;i++){
            power2[i] = (2LL * power2[i-1]) % mod;
        }


        while(l<=r){
            if(nums[l] + nums[r] <= target){
                // count all valid subsequences starting with left
                // ans += (r-l+1);  ->  You are counting elements, but you actually need to count subsequences.
                //count -> 2 ^ (r-l)    -> as including left other element a=has 2 option -> include or exclude
                ans = (ans + power2[r-l]) % mod;
                l++;
            }
            else{
                // current maximum is too large
                r--;
            }
        }
        return ans % mod;
    }
};