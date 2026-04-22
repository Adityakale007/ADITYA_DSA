class Solution {
public:
    double dp[101][101];
    double rec(int poured, int i, int j){

        if(j < 0    ||   j > i)return 0;

        if(j == 0 && i == 0)return poured;

        if(dp[i][j] != -1)
            return dp[i][j];

        //rec(4,2) = overflow from rec(3,1) + overflow from rec(3,2)
        //Each glass computed once → O(100²)
        
        double left = rec(poured , i - 1 , j - 1);
        double right = rec(poured , i - 1 , j);

        double leftOverflow = max(0.0 , (left - 1.0)/2.0);
        double rightOverflow = max(0.0 , (right - 1.0)/2.0);

        return dp[i][j] = (leftOverflow + rightOverflow);
    }

    double rec_bottom_up(int poured, int query_row, int query_glass){
        // “How much flows from each glass to the next row?”
        // We start from the top and propagate overflow downward.

        vector<vector<double>> dp(101, vector<double>(101, 0.0));
        dp[0][0] = poured;

        for(int i=0;i<query_row;i++){
            for(int j=0;j<=i;j++){

                if(dp[i][j] > 1.0){
                    double overflow = (dp[i][j] - 1.0)/2.0;

                    dp[i+1][j] += overflow;
                    dp[i+1][j+1] += overflow;

                    dp[i][j] = 1.0;// glass stays full
                }
            }
        }
        return min(1.0 , dp[query_row][query_glass]);
    }

    double champagneTower(int poured, int query_row, int query_glass) {
        //my intuition is dp cause recursion is used
        // Why Dynamic Programming?
        // Because:
        //         Every glass depends only on the previous row.
        //         The tower height is small (≤ 100).



        //  for (int i = 0; i < 101; i++){
        //     for (int j = 0; j < 101; j++){
        //         dp[i][j] = -1.0;
        //     }
        //  }
                
        // double ans = rec(poured,query_row,query_glass);
        // return min(1.0 , ans);
        return rec_bottom_up(poured,query_row,query_glass);
    }
};