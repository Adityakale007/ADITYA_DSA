class Solution {
public:
    bool check(vector<vector<int>>& mat,int row,int col,int m,int n){
        int cnt = 0;
        for(int i=0;i<m;i++){
            if(mat[i][col] != 0)cnt++;
            if(cnt>1)return false;
        }

        cnt = 0;

        for(int i=0;i<n;i++){
            if(mat[row][i] != 0)cnt++;
            if(cnt>1)return false;
        }

        return true;
    }
    int numSpecial(vector<vector<int>>& mat) {
        int ans = 0;

        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j] == 1){
                    if(check(mat,i,j,mat.size(),mat[0].size()))ans++;
                }
            }
        }
        return ans;
    }
};