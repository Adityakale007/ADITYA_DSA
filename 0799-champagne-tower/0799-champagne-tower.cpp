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

    double champagneTower(int poured, int query_row, int query_glass) {
        //my intuition is dp cause recursion is used
        // Why Dynamic Programming?
        // Because:
        //         Every glass depends only on the previous row.
        //         The tower height is small (≤ 100).

         for (int i = 0; i < 101; i++){
            for (int j = 0; j < 101; j++){
                dp[i][j] = -1.0;
            }
         }
                
        double ans = rec(poured,query_row,query_glass);
        return min(1.0 , ans);
    }
};