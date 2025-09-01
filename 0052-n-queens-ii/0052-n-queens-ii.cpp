class Solution {
public:

    bool isValid(int row,int col,vector<string>& board,int n){
        int x = row;
        int y = col;
        //checking columns -> only for left as we are filling queens in right direction
        while(y>=0){
            if(board[x][y] == 'Q')
                return false;

            y--;
        }

        //no need to check row as in each column we are filling only 1 queen

        x = row;
        y = col;
        //checking upper diagonal -> only for left as we are filling queens in right direction
        while(x>=0 && y>=0){
            if(board[x][y] == 'Q')
                return false;

            x--;
            y--;
        }

        x = row;
        y = col;
        //checking lower diagonal -> only for left as we are filling queens in right direction
        while(x<n && y>=0){
            if(board[x][y] == 'Q')
                return false;

            x++;
            y--;
        }
        return true;
    }

    void solve(int col, int &ans,vector<string>& board,int n){
        if(col == n){
            ans++;
            return;
        }

        //solve one case ..and let recursion do other
        for(int row=0;row<n;row++){
            if(isValid(row,col,board,n)){
                board[row][col] = 'Q';
                solve(col+1 , ans,board,n);
                //backtrack
                board[row][col] = '.';
            }
        }
    }

    int totalNQueens(int n) {
        vector<string> board(n , string(n , '.'));
        int ans = 0;

        solve(0,ans,board,n);

        return ans;
    }
};