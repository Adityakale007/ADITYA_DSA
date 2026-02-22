class Solution {
public:
    string toBinary(int n){
        if(n == 0)return "";
        string ans = "";
        while(n>0){
            ans = char('0' + (n%2)) + ans;
            n /= 2;
        }
        return ans;
    }
    int binaryGap(int n) {
        string s = toBinary(n);
        int maxLength = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] == '1'){
                for(int j=i+1;j<s.size();j++){
                    if(s[j] == '0')continue;

                    maxLength = max(maxLength , j-i);
                    break;
                }
            }
        }
        return maxLength;
    }
};