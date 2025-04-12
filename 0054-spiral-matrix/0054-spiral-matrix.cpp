class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;

        int row = matrix.size();
        int column = matrix[0].size();

        //index initialization
        int startingrow = 0;
        int endingrow = row - 1;
        int startingcolumn = 0;
        int endigcolumn = column - 1;

        int total = row * column;
        int count = 0;
        while (count < total) {

            // starting row
            for (int i = startingcolumn ; count < total && i <= endigcolumn;i++) {
                ans.push_back(matrix[startingrow][i]);
                count++;
            }
            startingrow++;

            // ending coloumn
            for (int i = startingrow ; count < total && i <= endingrow; i++) {
                ans.push_back(matrix[i][endigcolumn]);
                count++;
            }
            endigcolumn--;

            // ending row
            for (int i = endigcolumn; count < total && i >= startingcolumn;i--) {
                ans.push_back(matrix[endingrow][i]);
                count++;
            }
            endingrow--;

            // starting coloumn
            for (int i = endingrow; count < total && i >= startingrow; i--) {
                ans.push_back(matrix[i][startingcolumn]);
                count++;
            }
            startingcolumn++;
        }
        return ans;
    }
};