class Solution {
public:
    // Manual popcount (count set bits in binary form)
    int popcount(long long x) {
        int cnt = 0;
        while (x > 0) {
            if (x % 2 == 1)
                cnt++;
            x /= 2;
        }
        return cnt;
    }

    int makeTheIntegerZero(int num1, int num2) {
        long long n1 = num1; // Cast to long long
        long long n2 = num2; // Cast to long long
        for (int k = 1; k <= 60; k++) {
            long long val = n1 - k * n2;
            if (val < k)
                continue; // must be at least k
            int bits = popcount(val);
            if (bits <= k)
                return k;
        }
        return -1;
    }
};