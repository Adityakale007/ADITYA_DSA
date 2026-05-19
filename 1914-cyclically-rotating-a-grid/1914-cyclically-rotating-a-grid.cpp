class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        int layers = min(m,n) / 2;
        int upper = 0;
        int right = m-1;
        int below = n-1;
        int left = 0;
        vector<int> temp;

        while(layers--){
            //upper
            for(int j=left;j<=right;j++){
                temp.push_back(grid[upper][j]);
            }
            
            //right
            for(int i= upper+1 ;i<= below-1 ;i++){
                temp.push_back(grid[i][right]);
            }

            //below
            for(int j=right;j>=left;j--){
                temp.push_back(grid[below][j]);
            }

            //left
            for(int i=below-1;i>= upper+1 ;i--){
                temp.push_back(grid[i][left]);
            }

            //now rotate k times
            int sz = temp.size();
            int rot = k % sz;
            
            vector<int> rotated(sz);
            for(int i=0;i<sz;i++){
                rotated[i] = temp[(rot + i) % sz];
            }

            //now put the rotated array back inside matrix
            int index = 0;
            //upper
            for(int j=left;j<=right;j++){
                grid[upper][j] = rotated[index];
                index++;
            }
            
            //right
            for(int i= upper+1 ;i<= below-1 ;i++){
                grid[i][right] = rotated[index];
                index++; 
            }

            //below
            for(int j=right;j>=left;j--){
                grid[below][j] = rotated[index];
                index++; 
            }

            //left
            for(int i=below-1;i>= upper+1 ;i--){
                grid[i][left] = rotated[index];
                index++; 
            }

            temp.clear();
            upper++;
            right--;
            below--;
            left++;
        }
        return grid;
    }
};