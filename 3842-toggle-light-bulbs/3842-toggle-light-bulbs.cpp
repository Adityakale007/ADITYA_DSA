class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& b) {
        int n = b.size();
        unordered_map<int,int>m;

        for(int i=0;i<n;i++){
            m[b[i]]++;
        }

        vector<int> ans;
        for(auto mp:m){
            if(mp.second % 2 != 0){
                ans.push_back(mp.first);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};