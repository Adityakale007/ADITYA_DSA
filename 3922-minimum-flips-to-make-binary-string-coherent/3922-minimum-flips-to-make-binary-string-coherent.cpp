class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        if(n<3)return 0;
        int ones = 0;
        int zeros = 0;
        for(int i=0;i<n;i++)
        {
            if(s[i] == '1')ones++;
            else zeros++;
        }

        // if(zeros == 0   ||  ones == 0){
        //     return 0;
        // }
        // else if(ones == 2   &&  (s[0] == '1' && s[n-1] == '1')){
        //     return 0;
        // }
        // return ones - 1;


        int a = max(ones - 1,0);
        int b = ones - (s[0] - '0') - (s[n-1] - '0');
        int c = zeros;
        return min({a,b,c});
    }
};