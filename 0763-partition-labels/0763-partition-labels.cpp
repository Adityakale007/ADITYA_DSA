class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        unordered_map<char,int>m;

        for(int i=0;i<n;i++){
            m[s[i]] = i+1;
        }

        vector<int>ans;
        int i=0;
        int last=-1;
        while(i<n){
            ans.push_back(m[s[i]]);
            last = m[s[i]];
            while(i<last && i<n){
                last = max(last,m[s[i]]);
                ans.back() = last;
                i++;
            }
        }

        for(int i=ans.size()-1;i>0;i--){
            ans[i] -= ans[i-1];
        }

        return ans;
    }
};