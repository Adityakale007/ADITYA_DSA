class Solution {
public:
    int numberOfSpecialChars(string words) {
        unordered_map<char,int>mp;
        for(char c:words){
            if(c >= 'a' &&   c <= 'z'){
                mp[c]++;
            }
        }
        int ans = 0;
        for(char c:words){
            if(c >= 'A' && c <= 'Z'){
                char target = tolower(c);
                if(mp.count(target)){
                    ans++;
                    mp.erase(target);
                }
            }
        }
        return ans;
    }
};