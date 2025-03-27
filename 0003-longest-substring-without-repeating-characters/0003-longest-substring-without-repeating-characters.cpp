class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)
        {
            return 0;
        }
        int cnt = 0;
        int start = 0;
        unordered_map<char,int> m;
        int n = s.length();
        int maxilength=1;
        for(int i = 0;i<n;i++){
            if(m.count(s[i])){
                start = max(start,m[s[i]] + 1);
                cnt = 0;
            }
            cnt++;
            m[s[i]]=i;
            maxilength = max(maxilength,i - start + 1);
        }
        if(cnt == s.length())return s.length();
        return maxilength;
    }
}; 