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

    bool hasAlternatingBits(int n) {
        string ans = toBinary(n);

        int m = ans.size();
        char flag = ans[0];
        for(int i=1;i<m;i++){
            if(flag != ans[i]){
                flag = ans[i];
            }
            else{
                return false;
            }
        }
        return true;
    }
};