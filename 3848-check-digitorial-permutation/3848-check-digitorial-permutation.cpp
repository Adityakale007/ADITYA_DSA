class Solution {
public:
    long long factorial(int n){
        if(n <= 1)return 1;

        return 1LL*n*factorial(n-1);
    }
    bool isDigitorialPermutation(int n) {
        long long sum = 0;
        string s = to_string(n);
        for(int i=0;i<s.size();i++){
            sum += factorial(s[i] - '0');
        }
        string ans = to_string(sum);
        sort(s.begin(),s.end());
        sort(ans.begin(),ans.end());
        
        return ans == s;
    }
};