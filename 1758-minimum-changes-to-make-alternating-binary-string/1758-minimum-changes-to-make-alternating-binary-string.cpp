class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        bool flag = 0;
        string s0 = "";
        for(int i=0;i<n;i++){
            s0 += (flag + '0');
            flag ^= 1;
        }
        flag = 1;
        string s1 = "";
        for(int i=0;i<n;i++){
            s1 += (flag + '0');
            flag ^= 1;
        }

        int cntFor0 = 0;
        int cntFor1 = 0;

        for(int i=0;i<n;i++){
            if(s[i] != s0[i])cntFor0++;
        }
        for(int i=0;i<n;i++){
            if(s[i] != s1[i])cntFor1++;
        }

        return min(cntFor0,cntFor1);
    }
};