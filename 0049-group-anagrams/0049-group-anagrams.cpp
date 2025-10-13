class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> vec(strs.begin(),strs.end());
        int n = vec.size();

        for(int i=0;i<n;i++){
            sort(vec[i].begin(),vec[i].end());
        }

        unordered_map<string , vector<string>> mp;
        for(int i=0;i<n;i++){
            mp[vec[i]].push_back(strs[i]);
        }

        vector<vector<string>> ans;
        for(auto &p:mp){
            ans.push_back(p.second);
        }
        return ans;
    }
};