class Solution {
public:
    int maxConsecutiveAnswers(string a, int k) {
        int n = a.size();
        int maxLength = 0;

        int l = 0;
        int r = 0;
        int maxf = 0;
        unordered_map<char,int>m;
        while(r<n){
            m[a[r]]++;
            maxf = max(maxf,m[a[r]]);

            int changes = (r-l+1) - maxf;

            if(changes <= k){
                maxLength = max(maxLength , r-l+1);
            }
            else{
                m[a[l]]--;
                if(m[a[l]] == 0)m.erase(a[l]);
                l++;
            }
            r++;
        }
        return maxLength;
    }
};