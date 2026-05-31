class Solution {
public:
    int digitFrequencyScore(int n) {
        unordered_map<int,int>mp;
        while(n>0){
            mp[n%10]++;
            n /= 10;
        }
        int ans = 0;
        for(auto m:mp){
            ans += (m.first * m.second);
        }
        return ans;
    }
};