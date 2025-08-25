class Solution {
public:
    int row[8] = {2,2,-2,-2,1,-1,1,-1};
    int col[8] = {1,-1,1,-1,2,2,-2,-2};

    bool isValid(int i,int j,int n){
        return i>=0&&j>=0&&i<n&&j<n ;
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();

        queue<pair<int,int>>q;
        q.push({0,0});
        
        if(grid[0][0] != 0)return false;

        int step = 0;

        while(!q.empty()){
            int count = q.size();
            int move = false;

            while(count--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                if(grid[i][j] != step )
                return false;

                if(step == n*n -1)
                return true;

                for(int k=0;k<8;k++){
                    int new_i = i + row[k];
                    int new_j = j + col[k];

                    if(isValid(new_i,new_j,n) && grid[new_i][new_j] == step + 1)
                    {
                        move = true;
                        q.push({new_i,new_j});
                    }
                }
            }
            if(move)step++;
        }
        return false;
    }
};