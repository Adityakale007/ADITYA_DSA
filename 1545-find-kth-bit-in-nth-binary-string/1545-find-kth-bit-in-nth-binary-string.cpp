class Solution {
public:
    string reverseInvert(string s){
        for(char &c:s){
            c ^= 1; //bits inverted
        }
        reverse(s.begin(),s.end());
        return s;
    }
    char findKthBit(int n, int k) {
        string ans = "0";
        string prev = ans;
        for(int i=1;i<n;i++){
            prev = ans;
            ans += "1";
            ans += reverseInvert(prev);
        }

        return ans[k-1];
    }
};