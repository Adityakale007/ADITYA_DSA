class Solution {
public:
    // long long toInteger(string s){
    //     long long ans = 0;
    //     for(char c:s){
    //         ans = ans*2 + (c - '0');
    //     }
    //     return ans;
    // }
    // string toBinary(long long n){
    //     if(n == 0)return "0";

    //     string ans = "";
    //     while(n>0){
    //         ans = char('0' + (n%2)) + ans;
    //         n /= 2;
    //     }
    //     return ans;
    // }
    string addBinary(string a, string b) {
        // long long x = toInteger(a);
        // long long y = toInteger(b);

        // long long sum = x+y;

        // string ans = toBinary(sum);
        // return ans;

        int carry = 0;
        string ans = "";

        int i = a.size()-1;
        int j = b.size()-1;

        while(i>=0 || j>=0 || carry){
            int sum = carry;

            if(i>=0){
                sum += a[i] -'0';
                i--;
            }

            if(j>=0){
                sum += b[j] -'0';
                j--;
            }

            ans += char('0' + sum%2);
            carry = sum/2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};