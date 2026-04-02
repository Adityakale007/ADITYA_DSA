class Solution {
public:
    int dp[500][500][3];
    int m,n;

    int rec(vector<vector<int>>& coins,int i,int j,int k){
        if(i >= m   ||  j >= n)return INT_MIN;

        //for last cell or or consider only one cell
        if(i == m-1     &&   j == n-1){
            if(coins[i][j] >= 0){
                return coins[i][j];
            }
            else{
                if(k>0){
                    return 0;
                }
                else{
                    return coins[i][j];
                }
            }
        }


        if(dp[i][j][k] != -1){
            return dp[i][j][k];
        }

        int right = rec(coins,i+1,j,k);
        int down = rec(coins,i,j+1,k);
        //int data type as it returns amount
        int best = max(right,down);

        int amount = 0;
        //positive element
        if(coins[i][j] >= 0){
            // amount = coins[i][j] + max(rec(coins,i+1,j,k),rec(coins,i,j+1,k));
            amount = coins[i][j] + best;
        }
        //negative element
        else{
            if(k>0){
                //include
                int include = coins[i][j] + best;
                //exclude
                int exclude = max(rec(coins,i+1,j,k-1),rec(coins,i,j+1,k-1));

                amount = max(include,exclude);
            }
            else{
                amount = coins[i][j] + best;
                // as negative will subtact on adding [(-2)+3 = 1]
            }
        }

        return dp[i][j][k] = amount;
    }

    int rec2(vector<vector<int>>& coins){
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(3,INT_MIN)));

        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                for(int k=0;k<=2;k++){
                    //handleing last index condition
                    if(i == m-1     &&      j == n-1){
                        if(coins[i][j] >= 0){
                            dp[i][j][k] = coins[i][j];
                        }
                        else{
                            if(k>0){
                                dp[i][j][k] = 0;
                            }
                            else{
                                dp[i][j][k] = coins[i][j];
                            }
                        }
                        continue;
                    }

                    int right  = (i+1 < m) ? dp[i+1][j][k] : INT_MIN;
                    int down = (j+1 < n) ? dp[i][j+1][k] : INT_MIN;
                    int best = max(right, down);

                    if(best == INT_MIN){
                        dp[i][j][k] = INT_MIN;
                        continue;
                    }

                    if(coins[i][j] >= 0){
                        dp[i][j][k] = coins[i][j] + best;
                    }
                    else{
                        if(k>0){
                            int include = coins[i][j] + best;

                            int right2  = (i+1 < m) ? dp[i+1][j][k-1] : INT_MIN;
                            int down2 = (j+1 < n) ? dp[i][j+1][k-1] : INT_MIN;
                            int exclude = max(right2, down2);

                            dp[i][j][k] = max(include,exclude);
                        }
                        else{
                            dp[i][j][k] = coins[i][j] + best;
                        }
                    }
                }
            }
        }
        return dp[0][0][2];
    }

    int maximumAmount(vector<vector<int>>& coins) {
        m = coins.size();
        n = coins[0].size();
        //this is a basic 3d dp question
        // memset(dp,-1,sizeof(dp));
        // return rec(coins,0,0,2);
        return rec2(coins);
    }
};  