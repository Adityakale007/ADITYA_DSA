class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n = words.size();
        string s = "abcdefghijklmnopqrstuvwxyz";

        string ans = "";
        for(int i=0;i<n;i++){
            int cnt = 0;
            for(int j=0;j<words[i].size();j++){
                cnt += weights[words[i][j] - 'a'];
            }
            cnt = cnt%26;
            ans += s[26 - cnt - 1];
        }
        return ans;
    }
};