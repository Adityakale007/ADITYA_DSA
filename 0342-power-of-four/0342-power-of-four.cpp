class Solution {
public:

    int solve(double n){
        if(n==1)return 1;
        if(n<1)return 0;

        return solve(n/4);
    }

    bool isPowerOfFour(int n) {
        return solve(n);
    }
};