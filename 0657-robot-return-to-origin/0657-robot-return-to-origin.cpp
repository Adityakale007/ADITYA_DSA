class Solution {
public:
    vector<int> rec(char &c,int l, int r)
    {
        if(c == 'L'){
            return {l-1,r};
        }
        else if(c == 'R'){
            return {l+1,r};
        }
        else if(c == 'U'){
            return {l,r+1};
        }
        else
            return {l,r-1};
    }
    bool judgeCircle(string moves) {
        int n = moves.size();
        vector<int>ans = {0,0};
        for(int i=0;i<n;i++)
        {
            int l = ans[0];
            int r = ans[1];
            ans = rec(moves[i],l,r);
        }
        return ans == vector<int>{0,0};
    }
};