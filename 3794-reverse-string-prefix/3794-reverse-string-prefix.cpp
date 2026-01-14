class Solution {
public:
    string reversePrefix(string s, int k) {
        int n = s.size();

        string a = "";
        string b = "";
        for(int i=0;i<n;i++){
            if(i<k){
                a += s[i];
            }
            else{
                b += s[i];
            }
        }

        reverse(a.begin(),a.end());
        string ans = a + b;
        return ans; 
    }
};