class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n = text.size();
        unordered_map<char,int>mp;
        for(int t:text)mp[t]++;

        return min({mp['b'] , mp['a'] , mp['l']/2 , mp['o']/2 , mp['n']});
    }
};