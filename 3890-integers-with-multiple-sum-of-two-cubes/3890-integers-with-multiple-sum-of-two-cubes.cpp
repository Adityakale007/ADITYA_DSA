class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        int m = pow(n,0.33333);
        vector<int>ans;
        unordered_map<int,int>mp;

        for(int a=1;a<=m;a++){
            for(int b = a;b<=m;b++){
                long long t = pow(a,3) + pow(b,3);
                mp[(int)t]++;
            }
        }

        for(auto m:mp){
            if(m.second >= 2){
                if(m.first <= n){
                    ans.push_back(m.first);
                }
            }
        }
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};