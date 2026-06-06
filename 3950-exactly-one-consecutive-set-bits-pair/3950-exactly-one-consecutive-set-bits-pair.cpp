class Solution {
public:
    string toBinary(int n){
        if (n == 0) return "0";

        string s = "";
        while(n>0){
            s = char('0' + (n%2)) + s;
            n /= 2;
        }
        return s;
    }

    bool consecutiveSetBits(int n) {
        string s = toBinary(n);
        int cnt = 0;
        for(int i=0;i<s.size()-1;i++){
            if(s[i] == '1'    &&  s[i] == s[i+1]){
                cnt++;
            }
        }

        return cnt==1;

    }
};