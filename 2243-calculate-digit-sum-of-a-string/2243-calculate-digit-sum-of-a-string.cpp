class Solution {
public:
    string digitSum(string s, int k) {
        int n = s.length();
        string ans = "";

        while(n > k){
            ans = "";
            for(int i=0;i<n;i += k){
                long long temp = 0;
                for(int j=i;j<min(i+k,n);j++){
                    temp += (s[j] - '0');
                }
                ans += to_string(temp);
            }
            s = ans;
            n=s.length();
        }
        return s;
    }
};