class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        int n = s.size();

        int d = 0;
        for(int i=0;i<n-1;i++){
            d = abs((s[i] - '0') - (s[i+1] - '0'));
            if(d > 2)return false;
        }
        return true;
        
    }
};