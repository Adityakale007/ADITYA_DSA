class Solution {
public:

    bool solve(double n){
        if(n==2)return 1;
        if(n<2)return 0;

        return solve(n/2);
    }

    bool isPowerOfTwo(int n) {
        if(n==1)return 1;
        return solve(n);
    }
};