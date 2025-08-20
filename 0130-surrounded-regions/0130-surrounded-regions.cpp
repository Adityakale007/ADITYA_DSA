class Solution {
public:
    int row;
    int col;

    int row_num[4] = {1,-1,0,0};
    int col_num[4] = {0,0,1,-1};

    bool isValid(int i,int j){
        return i>=0&&i<row&&j>=0&&j<col;
    }

    void solve(vector<vector<char>>& board) {
        row = board.size();
        col = board[0].size();

        queue<pair<int,int>> q;

        //top row
        for(int i=0;i<col;i++){
            if(board[0][i] == 'O'){
                q.push(make_pair(0,i));
                board[0][i] = 'T';
            }
        }
        //left col
        for(int i=1;i<row;i++){
            if(board[i][0] == 'O'){
                q.push(make_pair(i,0));
                board[i][0] = 'T';
            }
        }
        //bottom row
        for(int i=1;i<col;i++){
            if(board[row-1][i] == 'O'){

                q.push(make_pair(row-1,i));
                board[row-1][i] = 'T';
            }
        }

        //right col
        for(int i=0;i<row-1;i++){
            if(board[i][col-1] == 'O'){

                q.push(make_pair(i,col-1));
                board[i][col-1] = 'T';
            }
        }

        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();

            for(int k=0;k<4;k++){
                if(isValid(i+row_num[k],j+col_num[k])&&(board[i+row_num[k]][j+col_num[k]] == 'O')){
                    board[i+row_num[k]][j+col_num[k]] = 'T';
                    q.push(make_pair(i+row_num[k],j+col_num[k]));
                }
            }
        }

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j] == 'T')
                    board[i][j] = 'O';  //restored
                else if(board[i][j] == 'O')
                    board[i][j] = 'X';  //captured
            }
        }
    }
};