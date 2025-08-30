class Solution {
public:
    int getLeastFrequentDigit(int n) {
        string s = to_string(n);
        unordered_map<char,int> freq;

        for(int i=0;i<s.length();i++){
            if(freq.count(s[i])){
                freq[s[i]]++;
            }
            else{
                freq[s[i]] = 1;
            }
        }

        // for(auto a:s){
        //     freq[a]++;
        // }

        int ans = -1;
        int mini = INT_MAX;
        for(auto a:freq){
            if(a.second<mini){
                mini = a.second;
                ans = a.first - '0';
            }
            else if(a.second == mini){
                ans = min(ans,a.first - '0');
            }
        }
        return ans;
    }
};