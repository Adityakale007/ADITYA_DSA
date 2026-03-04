class Solution {
public:
    string maximumXor(string s, string t) {
        int zeros = 0;
        int ones = 0;
        for(int i=0;i<t.size();i++){
            if(t[i] == '0')zeros++;
            else ones++;
        }

        string ans = "";
        for(int i=0;i<s.size();i++){
            if(s[i] == '1' && zeros>0){
                zeros--;
                ans += '1';
            }
            else if(s[i] == '0' && ones>0){
                ones--;
                ans += '1';
            }
            else{
                ans += '0';
            }
        }

        return ans;
    }
};