class Solution {
public:
    int row[8] = {1,1,1,-1,-1,-1,0,0};
    int col[8] = {-1,0,1,-1,0,1,1,-1};

    bool isValid(int i,int j,int n){
        return i>=0&&j>=0&&i<n&&j<n ;
    }


    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n =grid.size();

        if(grid[0][0] != 0)
        return -1;

        if(n == 1)
        return 1;

        queue<pair<int,int>>q;
        q.push({0,0});
        grid[0][0] = 1;

        int step = 1;

        while(!q.empty()){
            int count = q.size();

            while(count--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                for(int k=0;k<8;k++){
                    int new_i = i+row[k];
                    int new_j = j+col[k];

                    if(isValid(new_i,new_j,n) && !grid[new_i][new_j])
                    {
                        if(new_i == n-1 && new_j == n-1)
                        return step+1;

                        grid[new_i][new_j] = 1;
                        q.push({new_i,new_j});
                    }
                }
            }
            step++;
        }
        return -1;
    }
};