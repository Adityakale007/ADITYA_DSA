class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size())return false;
        int n = s.size();
        s += s;
        int i = 0;
        vector<int>v;
        for(i=0;i<s.size();i++){
            if(s[i] == goal[0]){
                v.push_back(i);
            }
        }

        for(int i=0;i<v.size();i++){
            string t = s.substr(v[i],n);
            if(t == goal)return true;
        }
        return false;
    }
};