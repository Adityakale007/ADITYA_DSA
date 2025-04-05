//longest common subsequence
class Solution {
    private:
    int solve(string& a,string& b,int i,int j,vector<vector<int>>& dp){
        if(i == a.length())
            return 0;
        if(j == b.length())
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;
        if(a[i] == b[j]){
            ans = 1 + solve(a,b,i + 1,j + 1,dp);
        }
        else{
            ans = max(solve(a,b,i + 1,j,dp) , solve(a,b,i,j + 1,dp));
        }
        return dp[i][j] = ans;
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n+1 , vector<int> (m+1 , -1));
        int number = solve(word1,word2,0,0,dp);
        
        int solution1 = n - number;
        int solution2 = m - number;

        return solution1 + solution2;
    }
};