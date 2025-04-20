class Solution {
public:
    char findTheDifference(string s, string t) {
        char result = 0 ;
        for (int i = 0; i < s.length(); i++) { 
            result ^= s[i]; 
        }

        for (int i = 0; i < t.length(); i++) {
            result ^= t[i];
        }

        return result;
    }
};