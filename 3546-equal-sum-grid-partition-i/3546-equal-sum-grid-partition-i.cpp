class Solution {
public:
    bool canSplitHorizontally(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        vector<long long>v;
        for(int i=0;i<n;i++){
            long long sum = 0;
            for(int j=0;j<m;j++){
                sum += grid[i][j];
            }
            v.push_back(sum);
        }

        long long total = 0;
        for(int i:v){total += i;}

        long long prefix = 0;
        for(int i=0;i<n-1;i++){
            prefix += v[i];
            if(prefix == total - prefix)return true;
        }
        return false;
    }
    bool canSplitVertically(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        vector<long long>v;
        for(int j=0;j<m;j++){
            long long sum = 0;
            for(int i=0;i<n;i++){
                sum += grid[i][j];
            }
            v.push_back(sum);
        }

        long long total = 0;
        for(int i:v)total += i;

        long long prefix = 0;
        for(int i=0;i<m-1;i++){
            prefix += v[i];
            if(prefix == total - prefix)return true;
        }
        return false;
    }
    bool canPartitionGrid(vector<vector<int>>& grid) {
        return (canSplitHorizontally(grid)    ||  canSplitVertically(grid));
    }
};