class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int column = matrix[0].size();

            //transpose
        for(int i=0;i<row;i++){
            for(int j=i+1;j<column;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }

           //reverse
        for(int i=0;i<row;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};
