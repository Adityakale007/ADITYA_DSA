class Solution {
    private:
    int solve_TOP_DOWN(string& str, string& pattern,int i,int j,vector<vector<int>>& dp){
        if(i==0 && j==0)
            return true;
        if(i>0 && j==0) // pattern finished
            return false;
        if(i==0 && j>0){ // pattern remaining either * or any other character
            for(int k=1;k<=j;k++){
                if(pattern[k-1] != '*'){
                    return false; // * -> convert to empty
                }
            }
            return true;
        }

        if(dp[i][j] != -1)
            return dp[i][j];
        
        //if match
        if(str[i-1] == pattern[j-1] || pattern[j-1] == '?')
            return dp[i][j] = solve_TOP_DOWN(str,pattern,i - 1,j - 1,dp);
        
        else if(pattern[j-1] == '*'){
            // do deletion and putting *str respectivey
            return dp[i][j] = (solve_TOP_DOWN(str,pattern,i,j - 1,dp) || solve_TOP_DOWN(str,pattern,i - 1,j,dp));
        }
        else
            return false;
    }


    int solve_BOTTOM_UP(string& str, string& pattern){
        vector<vector<int>> dp(str.length() + 1 , vector<int> (pattern.length() + 1 , 0));
        dp[0][0] = true;
        //dp[i>0][0] = false already there
        for(int j=1;j<=pattern.length();j++){
            bool flag = true;
            for(int k=1;k<=j;k++){
                if(pattern[k-1] != '*'){
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag;
        }

        for(int i=1; i<=str.length(); i++){
            for(int j=1; j<=pattern.length(); j++){

                if(str[i-1] == pattern[j-1] || pattern[j-1] == '?'){
                    dp[i][j] =  dp[i-1][j-1];
                }
                else if(pattern[j-1] == '*'){
                    dp[i][j] = (dp[i-1][j] || dp[i][j-1]);
                }
                else{
                    dp[i][j] = false;
                }
            }
        }
        return dp[str.length()][pattern.length()];
    }


    int solve_SPACE_OPTIMISED(string& str, string& pattern){
        // vector<vector<int>> dp(str.length() + 1 , vector<int> (pattern.length() + 1 , 0));
        vector<int> curr(pattern.length() + 1 , 0);
        vector<int> prev(pattern.length() + 1 , 0);
        prev[0] = true;
        //dp[i>0][0] = false already there
        for(int j=1;j<=pattern.length();j++){
            bool flag = true;
            for(int k=1;k<=j;k++){
                if(pattern[k-1] != '*'){
                    flag = false;
                    break;
                }
            }
            prev[j] = flag;
        }

        for(int i=1; i<=str.length(); i++){
            for(int j=1; j<=pattern.length(); j++){

                if(str[i-1] == pattern[j-1] || pattern[j-1] == '?'){
                    curr[j] =  prev[j-1];
                }
                else if(pattern[j-1] == '*'){
                    curr[j] = (prev[j] || curr[j-1]);
                }
                else{
                    curr[j] = false;
                }
            }
            prev = curr;
        }
        return prev[pattern.length()];
    }
public:
    bool isMatch(string s, string p) {
        // vector<vector<int>> dp(s.length() + 1 , vector<int> (p.length() + 1 , -1));
        // return solve_TOP_DOWN(s,p,s.length(),p.length(),dp); //////////////making it 0-indexed -> 1-indexed
        // return solve_BOTTOM_UP(s,p);
        return solve_SPACE_OPTIMISED(s,p);
    }
};