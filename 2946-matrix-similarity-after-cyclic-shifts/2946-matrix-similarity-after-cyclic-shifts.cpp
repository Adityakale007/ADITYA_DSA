class Solution {
public:
    vector<vector<int>> cyclicShift(vector<vector<int>>& mat){
        int n = mat.size();
        int m = mat[0].size();

        for(int i=0;i<n;i+=2){
            int initial = mat[i][0];
            for(int j=0;j<m-1;j++){
                mat[i][j] = mat[i][j+1];
            }
            mat[i][m-1] = initial;
        }

        for(int i=1;i<n;i+=2){
            int initial = mat[i][m-1];
            for(int j=m-1;j>0;j--){
                mat[i][j] = mat[i][j-1];
            }
            mat[i][0] = initial;
        }

        return mat;
    }
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int number_of_cols = mat[0].size();
        int shift = k % number_of_cols;
        vector<vector<int>>temp1 = mat;

        while(shift>0){
            temp1 = cyclicShift(temp1);
            shift--;
        }
        if(temp1 == mat)return true;
        return false;
    }
};