class Solution {
public:
    bool checkOnesSegment(string s) {
        string s0 = s;
        string s1 = s;
        sort(s0.begin(),s0.end());
        sort(s1.begin(),s1.end(),greater<int>());

        return s == s0 || s == s1;
    }
};