class Solution {
public:
    int partitionString(string s) {
        int n = s.size();
        int cnt = 1; // as three breaks signifies 4 partitions

        unordered_map<char,int>m;
        for(int i=0;i<n;i++){
            if(m.count(s[i])){
                cnt++;
                m.clear();
            }
            m[s[i]]++;
        }
        return cnt;
    }
};