class Solution {
    //THIS IS DIGOT DP PROBLEM*********************************
public:
//1 <= low <= high <= 10^15

    // bool check(long long n){
    //     long long odd = 0;
    //     long long even = 0;

    //     while(n>0){
    //         odd += n%10;
    //         n /= 10;
    //         even += n%10;
    //         n /= 10;
    //     }
    //     if(odd < 1)return false;
    //     if(even < 1)return false;
    //     if(odd == even)return true;
    //     return false;
    // }
//dont work cause number can be too big that int and long long couldnt handle


    long long dp[20][500][2][2][2];
    const int MOD = 1e9 + 7;
    const int OFFSET = 200;
    string s;

    long long solve(int index,int diff,bool started, bool parity,bool tight){
        //started = whether a non-zero digit has appeared
        if(index == s.size())
            // valid only if started and balanced and at least 2 digits
            return (started && diff == 0) ? 1 : 0;
        // return (diff == 0 && s.size()>=2);
        // Incorrect base condition
        // This checks max length, not actual digit count.
        // You must ensure:
        // number_of_digits >= 2
        // which again requires a digitCount or started + length state.
        
        if(dp[index][diff + OFFSET][started][parity][tight] != -1) 
            return dp[index][diff + OFFSET][started][parity][tight];
            // started: have we placed first non-zero digit
            // parity: odd/even position of next digit -> if true means even
            // diff: oddSum − evenSum

        long long ans = 0;
        // if(tight){
        //     for(int i=0;i <= s[index] - '0';i++){
        //         if(i == s[index] - '0'){
        //             if((index + 1)%2 == 1){
        //                 ans = (ans + solve(index+1,diff+i,true));
        //             }
        //             else{
        //                 ans = (ans + solve(index+1,diff-i,true));
        //             }
        //         }
        //         else{
        //             if((index + 1)%2 == 1){
        //                 ans = (ans + solve(index+1,diff+i,false));
        //             }
        //             else{
        //                 ans = (ans + solve(index+1,diff-i,false));
        //             }
        //         }
        //     }
        // }
        // else{
        //     for(int i=0;i <= 9;i++){
        //         if((index + 1)%2 == 1){
        //                 ans = (ans + solve(index+1,diff+i,false));
        //             }
        //         else{
        //             ans = (ans + solve(index+1,diff-i,false));
        //         }
        //     }
        // }
        int limit = tight ? s[index] - '0' : 9;
        for(int i=0;i<=limit;i++){
            bool newTight = tight && i == limit;
            if(!started){
                if(i == 0){
                    // still leading zero
                    ans += solve(index+1,diff,false,0,newTight);
                }
                else{
                    // first digit → odd position
                    ans += solve(index+1,diff + i,true,1,newTight);//now parity=1 therefore for next as it will be even
                }
            }
            else{
                if(parity == 0){
                    // odd position
                    ans += solve(index+1,diff + i,true,1,newTight);
                }
                else{
                    // even position
                    ans += solve(index+1,diff - i,true,0,newTight);//now parity=0 therefore for next as it will be odd

                }
            }
        }
        return dp[index][diff + OFFSET][started][parity][tight] = ans;
    }

    long long connect(long long x){
        if(x<10)return 0;
        //as we need t contains at least two digits.

        s = to_string(x);

        memset(dp,-1,sizeof(dp));
        return solve(0,0,false,0,true); //parity = 0 as first is odd(the leftmost digit has position 1)given
    }

    long long countBalanced(long long low, long long high) {
        long long highAns = connect(high);
        long long lowAns = connect(low-1);

        return highAns - lowAns;
    }
};