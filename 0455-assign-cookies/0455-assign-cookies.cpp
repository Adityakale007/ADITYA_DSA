class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int n = g.size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            auto it = lower_bound(s.begin(),s.end(),g[i]);
            if(it != s.end()){
                cnt++;
                // int index = it - s.begin();
                // s[index] = 0;
                s.erase(it);
                if(s.size() == 0)return cnt;
            }
        }

        return cnt; 
    }
};