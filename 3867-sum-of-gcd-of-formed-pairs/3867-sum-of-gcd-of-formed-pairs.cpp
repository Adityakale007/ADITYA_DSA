class Solution {
public:
    long long gcd(long long a,long long b){
        if(b == 0){
            return a;
        }
        return gcd(b,a%b);
    }
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int>v(n);
        int maxi = 0;
        for(int i=0;i<n;i++){
            maxi = max(maxi , nums[i]);
            v[i] = gcd(nums[i],maxi);
        }

        long long sum = 0;

        sort(v.begin(),v.end());
        int l = 0;
        int r = n-1;

        while(l<r){
            sum += gcd(v[l] , v[r]);
            l++;
            r--;
        }
        return sum;
    }
};