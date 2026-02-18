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
    int hammingWeight(int n) {
        string ans = toBinary(n);
        int cnt = 0;
        for(int i=0;i<ans.size();i++){
            if(ans[i] == '1')cnt++;
        }
        return cnt;
    }
};