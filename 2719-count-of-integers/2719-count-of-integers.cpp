// Why Digit DP?

// Constraints force us to:
// Process numbers digit-by-digit
// Enforce upper bound (≤ num2)
// Enforce lower bound (≥ num1)
// Track digit sum efficiently

// Digit DP allows:
// Efficient enumeration of all valid numbers ≤ N
// State reuse via memoization

class Solution {
public:
    long dp[23][401][2];
    int MOD = 1e9 + 7;


    long solve(int index,int sum,bool tight,const int &min_sum, const int &max_sum, string &s){
        //base case
        //to see if number is small then whart will be the ans
        if (sum > max_sum) return 0;
        if(index == s.size())
            return sum >= min_sum && sum <= max_sum;
            // Check if digit sum is within range
            // Return 1 (valid) or 0 (invalid)
        
        if(dp[index][sum][tight] != -1)
            return dp[index][sum][tight];
        

        long ans = 0;
        // tight answers one precise question:
        // Are all the digits chosen so far exactly equal to the prefix of the limit number (s)?

        // tight = true
        // → So far, the number you are building matches s[0..idx-1]

        // tight = false
        // → At some earlier position, you chose a smaller digit, so the number is already strictly smaller than s
        // This is how Digit DP enforces x ≤ s.

        if(tight){
            for(int i=0;i<=(s[index] - '0');i++){

                if(i == (s[index] - '0')){
                    ans = (ans + solve(index+1,sum+i,true,min_sum,max_sum,s)) % MOD;
                }
                else{
                    ans = (ans + solve(index+1,sum+i,false,min_sum,max_sum,s)) % MOD;
                }
            }
        }
        else{
            for(int i=0;i<=9;i++)
            {
                ans = (ans + solve(index+1,sum+i,false,min_sum,max_sum,s)) % MOD;
            }
        }
        return dp[index][sum][tight] = ans;
    }


    int count(string num1, string num2, int min_sum, int max_sum) {
        memset(dp,-1,sizeof(dp));
        long upper = solve(0,0,true,min_sum,max_sum,num2);
        memset(dp,-1,sizeof(dp));
        long lower = solve(0,0,true,min_sum,max_sum,num1);
        // What We Compute Instead

        // We compute:
        // upper = count(num2);   // valid x in [0, num2]
        // lower = count(num1);   // valid x in [0, num1]
        // Now look carefully:

        // upper - lower gives:
        // (count of [0, num2]) - (count of [0, num1])
        // = count of (num1, num2]

        // 👉 Notice: num1 is excluded.
        // But the problem wants:
        // [num1, num2]
        // So we need to add num1 back IF it is valid.

        int sum = 0;
        for(int i=0;i<num1.size();i++){
            sum += (num1[i] - '0');
        }
        if(sum >= min_sum && sum <= max_sum)
            lower--;
            // Checks if num1 itself is a valid number
            // If yes:
            // Remove it from lower
            // So subtraction becomes correct

        return ((upper - lower)+ MOD)%MOD;
        // (upper - lower)%MOD; not this ans to make it positive
    }
};