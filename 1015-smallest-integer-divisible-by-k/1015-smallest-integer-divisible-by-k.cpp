class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k%2 == 0 || k%5 == 0)return -1;
        // int cnt = 1;
        // long long i = 1;
        // for(int j = 0;j<100000;j++){
        //     if(i%k == 0)return cnt;
        //     cnt++;
        //     i = i*10 + 1;
        // }

        // Modular Arithmetic Rule
        // (a×10+1)% k=((a % k)×10+1)% k
        // You are not building 111111
        // You are only tracking remainders
        int remainder = 0;
        for(int len=1;len<=k;len++){
            remainder = (remainder*10 +1)%k;
            if(remainder == 0)return len;
        }

        return -1;
    }
};