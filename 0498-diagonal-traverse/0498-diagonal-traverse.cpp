class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int i = 0;
        int j = 0;
        

        vector<int> result;

        while(result.size() < m*n){

                result.push_back(mat[i][j]);

                if((i+j)%2 == 0)//move up-right
                {
                    if(j==n-1){
                        i++;
                    }
                    else if(i==0){
                        j++;
                    }
                    else{
                        i--;
                        j++;
                    }
                }
                else{   //move down-left
                    if(i==m-1){
                        j++;
                    }
                    else if(j==0){
                        i++;
                    }
                    else{
                        i++;
                        j--;
                    }
                }
        }

        return result;
    }
};