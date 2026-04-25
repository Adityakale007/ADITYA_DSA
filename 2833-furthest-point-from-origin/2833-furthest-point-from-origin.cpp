class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int cntL = 0;
        int cntR = 0;
        int cnt_ = 0;
        int ans = 0;
        int n = moves.size();

        for(int i=0;i<n;i++)
        {
            if(moves[i] == 'L'){
                cntL++;
            }
            else if(moves[i] == 'R'){
                cntR++; 
            }
            else{
                cnt_++;
            }
        }

        if(cntL >= cntR){
            cntL += cnt_;
            ans = (cntL - cntR);
        }
        else{
            cntR += cnt_;
            ans = (cntR - cntL);
        }
        return ans;
    }
};