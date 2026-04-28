class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {  //this is great sol with O(n) time complexity
        int n = prices.size();
        long long ans = n;
        int i = 0;

        while(i<n){
            int j=i;
            int cnt = 0;
            while(j<n-1 && prices[j+1] + 1 == prices[j]){
                cnt++;
                ans += cnt;
                j++;
            }
            i = j+1;
        }
        return ans;
    }
};