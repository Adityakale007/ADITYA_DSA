class Solution {
public:
    int numberOfDivisors(int n){
        int cnt = 0;
        int sum = 0;
        for(int i=1;i*i <= n;i++){
            if(n%i == 0){
                int d1 = i;
                int d2 = n/i;

                if(d1 == d2){
                    cnt++;
                    sum += d1;
                }
                else{
                    cnt+=2;
                    sum+=(d1+d2);
                }
                if(cnt>4)return 0;
            }
        }
        return (cnt == 4) ? sum : 0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += numberOfDivisors(nums[i]);
        }
        return ans;
    }
};