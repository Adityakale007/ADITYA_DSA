class Solution {
public:
    char nextGreatestLetter(vector<char>& l, char target) {
        int n = l.size();
        sort(l.begin(),l.end());
        for(int i=0;i<n;i++){
            if(l[i] > target)return l[i];
        }
        return l[0];
    }
};