class Solution {
    private:
    int solve_TOP_DOWN(string& a,string& b,int i,int j,vector<vector<int>>& dp){
        //base case
        if(i == a.length())
            return b.length() - j; // as insert operation
        if(j == b.length())
            return a.length() - i; // as deletion opertion

        if(dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;
        if(a[i] == b[j]){
            ans = solve_TOP_DOWN(a,b,i + 1,j + 1,dp);
        }
        else{
            //insert
            int insertANS = 1 + solve_TOP_DOWN(a,b,i,j + 1,dp);
            //delete
            int deleteANS = 1 + solve_TOP_DOWN(a,b,i + 1,j,dp);
            //replace
            int replaceANS = 1 + solve_TOP_DOWN(a,b,i + 1,j + 1,dp);

            ans = min(insertANS, min(deleteANS , replaceANS));
        }
        return dp[i][j] = ans;
    }


    int solve_BOTTOM_UP(string& a,string& b){
        int n = a.length();
        int m = b.length();
        vector<vector<int>> dp(n+1 , vector<int> (m+1 , 0));
        //base case
        for(int j=0; j<m; j++){
            dp[a.length()][j] = b.length() - j;
        }
        for(int i=0; i<n; i++){
            dp[i][b.length()] = a.length() - i;
        }

        for(int i = n-1; i>=0; i--){
            for(int j = m-1; j>=0; j--){

                int ans = 0;
                if(a[i] == b[j]){
                    ans = dp[i + 1][j + 1];
                }
                else{
                    //insert
                    int insertANS = 1 + dp[i][j + 1];
                    //deete
                    int deleteANS = 1 + dp[i + 1][j];
                    //replace
                    int replaceANS = 1 + dp[i + 1][j + 1];

                    ans = min(insertANS , min(deleteANS , replaceANS));
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }

    int solve_SPACE_OPTIMESED(string& a,string& b){
        int n = a.length();
        int m = b.length();
        // vector<vector<int>> dp(n+1 , vector<int> (m+1 , 0));
        // //base case
        // for(int j=0; j<m; j++){
        //     dp[a.length()][j] = b.length() - j;
        // }
        // for(int i=0; i<n; i++){
        //     dp[i][b.length()] = a.length() - i;
        // }
        vector<int> curr (m+1 , 0);
        vector<int> next (m+1 , 0);
        //base case
        for(int j=0; j<m; j++){
            next[j] = b.length() - j;
        }

        for(int i = n-1; i>=0; i--){
            for(int j = m-1; j>=0; j--){

                //base case
                curr[b.length()] = a.length() - i;

                int ans = 0;
                if(a[i] == b[j]){
                    ans = next[j + 1];
                }
                else{
                    //insert
                    int insertANS = 1 + curr[j + 1];
                    //deete
                    int deleteANS = 1 + next[j];
                    //replace
                    int replaceANS = 1 + next[j + 1];

                    ans = min(insertANS , min(deleteANS , replaceANS));
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        // vector<vector<int>> dp(n+1 , vector<int> (m+1 , -1));
        // return solve_TOP_DOWN(word1,word2,0,0,dp);
        // return solve_BOTTOM_UP(word1,word2);
        if(word1.length() == 0)
            return word2.length();
        if(word2.length() == 0)
            return word1.length();
        return solve_SPACE_OPTIMESED(word1,word2);

    }
};