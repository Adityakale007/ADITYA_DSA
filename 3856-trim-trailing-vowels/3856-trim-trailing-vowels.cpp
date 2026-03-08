class Solution {
public:
    string trimTrailingVowels(string s) {
        vector<char>v{'a','e','i','o','u'};
        int n = s.size();
        for(int i=n-1;i>=0;i--){
            bool flag = false;
            for(int j=0;j<5;j++){
                if(s[i] == v[j]){
                    flag = true;
                    s[i] = '0';
                }
            }
            if(!flag)break;
        }
        string ans = "";
        for(int i=0;i<n;i++){
            if(s[i] != '0'){
                ans += s[i];
            }
            else{
                break;
            }
        }
        return ans;
    }
};