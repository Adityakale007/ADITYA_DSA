class Solution {
    private:
    bool IsSafe(int row,int col,vector<vector<char>>& board,int val){
        char charVal = val + '0';
        for(int i = 0;i<board[0].size();i++){
            //check row
            if(board[row][i] == charVal){
                return false;
            }
            //check column
            if(board[i][col] == charVal){
                return false;
            }
            //check 3x3 matrix
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == charVal){
                return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board){
        int n = board[0].size();
        for(int row = 0;row<n;row++){
            for(int col = 0;col<n;col++){
                if(board[row][col]== '.'){
                    for(int val = 1;val<=9;val++){
                        if(IsSafe(row,col,board,val)){
                            char charVal = val + '0';
                            board[row][col] = charVal;

                            //recursion call
                            bool solutionPossible = solve(board);

                            if(solutionPossible){
                                return true;
                            }
                            else{
                                //backtrack
                                board[row][col] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};