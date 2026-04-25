class Solution {
public:
    bool validDigit(int n, int x) {
        string s = to_string(n);
        unordered_map<char,int>mp;
        for(int i = 0;i<s.size();i++){
            mp[s[i]]++;
        }
        char t = x + '0';
        return ((mp[t] >= 1) && (s[0] != x + '0'));
    }
};