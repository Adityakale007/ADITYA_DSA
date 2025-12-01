class Solution {
public:
    int maxDistinct(string s) {
        int n = s.length();
        unordered_map<char,int>freq;

        for(int i=0;i<n;i++){
            freq[s[i]]++;
        }

        return freq.size();
    }
};