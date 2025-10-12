class Solution {
public:
    bool isBalanced(unordered_map<char,int> &mp){
        int maxi = INT_MIN;
        int mini = INT_MAX;

        for(auto &p:mp){
            maxi = max(maxi,p.second);
            mini = min(mini,p.second);
        }

        return maxi == mini;
    }

    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;

        for(int i=0;i<n;i++){
            unordered_map<char,int>mp;
            for(int j=i;j<n;j++){
                mp[s[j]]++;

                if(isBalanced(mp)){
                    int length = j-i+1;
                    ans = max(ans,length);
                }
            }
        }
        return ans;
    }
};