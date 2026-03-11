class Solution {
public:
    string toBinary(int n){
        if(n == 0)return "0";

        string ans = "";
        while(n>0){
            ans = char('0' + (n%2)) + ans;
            n /= 2;
        }
        return ans;
    }
    int toDecimal(string s){
        int n = 0;
        for(char c:s)
        {
            n = n*2 + (c - '0');
        }
        return n;
    }

    int bitwiseComplement(int n) {
        string ans = toBinary(n);
        for(int i=0;i<ans.size();i++){
            ans[i] ^= 1;
        }
        return toDecimal(ans);
    }
};