class Solution {
public:
    long long divide(long long dividend, long long divisor) {
        long long n = dividend / divisor;
        if(n > INT_MAX)return INT_MAX;
        if(n < INT_MIN)return INT_MIN;
        return n;
    }
};