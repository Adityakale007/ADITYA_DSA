class Solution {
public:
    string toBinary(int n){
        if (n == 0) return "0";

        string binary = "";
        while (n > 0) {
            binary = char('0' + (n % 2)) + binary; // prepend remainder
            n /= 2;
        }
        return binary;
    }

    bool check(string s){
        int n = s.size();
        unordered_map<char,int>m;
        for(int i:s){
            m[i]++;
        }
        return m.size()==1;
    }

    int countMonobit(int n) {
        int cnt = 0;

        for(int i=0;i<=n;i++){
            string s = toBinary(i);
            if(check(s))cnt++;
        }

        return cnt;
    }
};