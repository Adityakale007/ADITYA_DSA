class Solution {
public:
    int reverse(int n){
        int digit = 0;
        while(n>0){
            digit = digit*10 + n % 10;
            n /= 10;
        }
        return digit;
    }
    int mirrorDistance(int n) {
        int r = reverse(n);
        return abs(n - r);
    }
};