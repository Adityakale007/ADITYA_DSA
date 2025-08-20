class Solution {
public:
    int row;  
    int col;

    int  row_num[4] = {1,-1,0,0};
    int  col_num[4] = {0,0,1,-1};

    bool isValid(int i,int j){
        return i>=0&&i<row&&j>=0&&j<col;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();

        //BFS
        queue<pair<int,int>>q;
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j] == 2)
                    q.push(make_pair(i,j));
            }
        }

        int timer = 0;

        while(!q.empty()){
            int curr_member = q.size();
            bool infected = false;

            while(curr_member--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                for(int k=0;k<4;k++){
                    if(isValid(i+row_num[k],j+col_num[k])&&(grid[i+row_num[k]][j+col_num[k]] == 1)){
                        grid[i+row_num[k]][j+col_num[k]] = 2;
                        q.push(make_pair(i+row_num[k],j+col_num[k]));
                        infected = true;
                    }
                }
            }
            if(infected)timer++;
        }

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j] == 1)
                    return -1;
            }
        }

        return timer;
    }
};