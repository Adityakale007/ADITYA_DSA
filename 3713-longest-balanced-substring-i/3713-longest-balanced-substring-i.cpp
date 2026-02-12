class Solution {
public:
    bool check(unordered_map<char,int>& mp){
        if(!mp.size())return true;

        int num = mp.begin()->second;

        for(auto m:mp){
            if(m.second != num)return false;
        }
        return true;
    }
    int longestBalanced(string s) {
        int n = s.size();
        int maxLength = 0;
        unordered_map<char,int>m;

        for(int i=0;i<n;i++){
            m.clear();
            for(int j=i;j<n;j++){
                m[s[j]]++;

                if(check(m)){
                    maxLength = max(maxLength,j-i+1);
                }
            }
        }
        return maxLength;
    }
};