class Solution {
public:
    int numberOfSpecialChars(string words) {
        unordered_map<char,pair<int,int>>mp;  //->(freq,last_occurance)
        for(int i=0;i<words.size();i++){
            if(words[i] >= 'a' &&   words[i] <= 'z'){
                mp[words[i]].first += 1;
                mp[words[i]].second = i;
            }
        }
        int ans = 0;
        for(int i=0;i<words.size();i++){
            if(words[i] >= 'A' && words[i] <= 'Z'){
                char target = tolower(words[i]);
                if(mp.count(target)){
                    if(i > mp[target].second){
                        ans++;
                    }
                    mp.erase(target);
                }
            }
        }
        return ans;
    }
};