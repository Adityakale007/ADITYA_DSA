class Solution {
public:
    int row[8] = {-1,-1,-1,1,1,1,0,0};
    int col[8] = {1,-1,0,0,1,-1,1,-1};

    bool isValid(int i,int j,int n,int m){
        return i>=0&&j>=0&&i<n&&j<m ;
    }

    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> temp(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int count = 0;
                for(int k=0;k<8;k++){
                    int new_i = i+row[k];
                    int new_j = j+col[k];

                    if(isValid(new_i,new_j,n,m)){
                        count += board[new_i][new_j];
                    }
                }
                temp[i][j] = count;
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int report = temp[i][j];
                if(board[i][j] == 1){
                    if(report < 2  || report > 3){
                        board[i][j] = 0;
                    }
                }
                else{
                    if(report == 3){
                        board[i][j] = 1;
                    }
                }
            }
        }
    }
};