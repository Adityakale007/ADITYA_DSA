class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int x = max(1 , n-k);
        int end = k+n;

        int cnt = 0;

        while(x <= end){
            if((n & x) == 0){
                cnt += x;
            }
            x++;
        }
        return cnt;
    }
};