class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        int n = h.size();
        sort(h.begin(),h.end());
        long long ans = 0;
        int p = 0;

        for(int i=n-1;i>=0;i--)
        {
            if(h[i] >= p){
                h[i] = h[i] - p;
            }
            else{
                h[i] = 0;
            }
            p++;
        }
        
        p = 1;
        while(k>0){
            ans += h[n-p];
            k--;
            p++;
        }

        return ans;
    }
};