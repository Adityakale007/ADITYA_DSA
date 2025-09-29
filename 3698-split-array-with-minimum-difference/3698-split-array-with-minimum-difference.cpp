class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        vector<bool> inc(n),dec(n);

        inc[0] = true;
        dec[n-1] = true;

        for(int i=1;i<n;i++){
            if(inc[i-1] && nums[i] > nums[i-1]){
                inc[i] = true;
            }else{
                inc[i] = false;
            }
        }

        for(int i=n-2;i>=0;i--){
            if(dec[i+1] && nums[i] > nums[i+1]){
                dec[i] = true;
            }else{
                dec[i] = false;
            }
        }

        long long ans = LLONG_MAX;

        for(int i=0;i<n-1;i++){
            if(inc[i] && dec[i+1]){
                long long left = 0;
                long long right = 0;

                for(int j=0;j<=i;j++){
                    left += nums[j];
                }

                for(int j=i+1;j<n;j++){
                    right += nums[j];
                }

                long long temp = llabs(left - right);
                ans = min(ans,temp);
            }
        }
        return (ans == LLONG_MAX ? -1 : ans);
    }
};