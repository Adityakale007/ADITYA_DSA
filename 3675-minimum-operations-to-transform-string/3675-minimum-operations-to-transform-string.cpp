class Solution {
public:
    int minOperations(string s) {
        int diff = INT_MAX;
        int distance = 0;

        sort(s.begin(),s.end());

        for(int i=0;i<s.length();i++){
            distance  = abs(s[i] - 'a');
            if(distance == 0)continue;
            diff = min(distance,diff);
        }

        if(distance == 0)return 0;

        return 26 - diff;
    }
};