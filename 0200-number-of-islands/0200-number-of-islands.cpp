class Solution {
public:
    int row=0;
    int col=0;

    int row_num[4] = {1,-1,0,0};
    int col_num[4] = {0,0,1,-1};

    bool isValid(int i,int j){
        return i>=0&&i<row&&j>=0&&j<col;
    }

    int numIslands(vector<vector<char>>& grid) {
        row = grid.size();
        col = grid[0].size();

        queue<pair<int,int>> q;
        int count = 0;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j] == '1')
                {
                    count++;
                    //make all 1 convert to 0
                    grid[i][j] = '0';
                    q.push(make_pair(i,j));

                    
                    while(!q.empty()){
                        int i = q.front().first;
                        int j = q.front().second;
                        q.pop();

                        for(int k=0;k<4;k++){
                            if(isValid(i+row_num[k],j+col_num[k])&&(grid[i+row_num[k]][j+col_num[k]] == '1')){
                                grid[i+row_num[k]][j+col_num[k]] = '2';
                                q.push(make_pair(i+row_num[k],j+col_num[k]));
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};