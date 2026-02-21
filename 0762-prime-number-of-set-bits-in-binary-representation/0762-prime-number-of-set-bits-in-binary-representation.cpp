class Solution {
public:
    bool isPrime(int n){
        if(n == 0)return false;
        if(n == 1)return false;
        for(int i=2;i<n;i++){
            if(n%i == 0)return false;
        }
        return true;
    }
    string toBinary(int n){
        if(n == 0)return "0";
        string ans = "";
        while(n>0){
            ans = char('0' + (n%2)) + ans;
            n /= 2;
        }
        return ans;
    }
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for(int i=left ; i<=right;i++){
            string s = toBinary(i);
            int cnt = 0;
            for(int i=0;i<s.size();i++){
                if(s[i] == '1')cnt++;
            }
            if(isPrime(cnt))ans++;
        }

        return ans;
    }
};