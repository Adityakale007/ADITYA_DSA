class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        sort(piles.begin(),piles.end());

        int ans = 0;
        int count = n/3;

        for(int i=n-2;i>=0;i -= 2){
            if(count>0){
                ans += piles[i];
                count--;
            }
        }
        return ans;
    }
};