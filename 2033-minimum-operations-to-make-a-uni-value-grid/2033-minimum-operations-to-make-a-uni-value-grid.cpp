class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m = grid[0].size();
        int avg = 0;

        vector<int>v;
        int modulo = grid[0][0] % x;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] % x == modulo){
                    v.push_back(grid[i][j]);
                    avg += grid[i][j];
                }
                else{
                    return -1;
                }
            }
        }
        // int y = ceil(avg/(m*n));
        // int eq = 0;
        sort(v.begin(),v.end());
        // auto it = lower_bound(v.begin(),v.end(),y);

        // if(it != v.end() && *it == y){
        //     eq = *it;
        // }
        // else if(it != v.begin()){
        //     it--;
        //     eq = *it;
        // }

        int eq = v[v.size()/2];
        int ans = 0;
        //now we need to make array elements equal to eq
        for(int i=0;i<v.size();i++){
            ans += (abs(v[i] - eq));
        }
        return ans/x;
    }
};