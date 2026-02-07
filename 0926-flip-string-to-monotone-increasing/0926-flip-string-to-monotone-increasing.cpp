class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        int oneCnt = 0;
        int minSwaps = 0;

        for(int i=0;i<n;i++)
        {
            if(s[i] == '1'){
                oneCnt++;
            }
            else{
                //s[i] == '0'
                //either swap all the previous one or delete this zero
                minSwaps = min(minSwaps + 1 , oneCnt);
            }
        }
        return minSwaps;
    }
};