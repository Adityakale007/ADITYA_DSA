class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int m = baskets.size();
        int cnt = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            int j=0;
            for(j=0;j<m;j++){
                if(fruits[i] <= baskets[j]){
                    cnt++;
                    baskets[j] = 0;

                    break;
                }
            }
            if(j == m){
                ans++;
            }
        }
        if(cnt == n)return 0;
        return ans;
    }
};