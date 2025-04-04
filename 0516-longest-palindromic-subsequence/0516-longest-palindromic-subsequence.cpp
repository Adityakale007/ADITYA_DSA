class Solution {
    private:
    int solve(string a,string b){
        int n = a.length();
        int m = b.length();
        vector<int> curr(m+1 , 0);
        vector<int> next(m+1 , 0);

        for(int i = n-1 ; i>=0; i--){
            for(int j = m-1; j>=0 ; j--){

                int ans = 0;
                if(a[i] == b[j]){
                    ans = 1 + next[j+1];
                }
                else{
                    ans = max(curr[j+1] , next[j]);
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];
    }
public:
    int longestPalindromeSubseq(string s) {
        string rev = s;
        reverse(rev.begin(),rev.end());
        return solve(s,rev);
    }
};