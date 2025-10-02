class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size();
        int m = boxGrid[0].size();
        vector<vector<char>> ans(m,vector<char> (n));

        for(int i=0;i<n;i++){
            int position = m-1;
            for(int j=m-1;j>=0;j--){
                if(boxGrid[i][j] == '*'){
                    position = j-1;
                }
                else if(boxGrid[i][j] == '#'){
                    boxGrid[i][j] = '.';
                    boxGrid[i][position] = '#';
                    position--;
                }
            }
        }
        


        //rotate
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i][j] = boxGrid[j][i];
            }
        }

        for(int i=0;i<m;i++)
        {
            reverse(ans[i].begin(),ans[i].end());
        }

        return ans;

    }
};