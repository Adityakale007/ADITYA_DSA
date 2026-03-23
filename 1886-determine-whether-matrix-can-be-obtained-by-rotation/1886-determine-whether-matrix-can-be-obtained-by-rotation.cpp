class Solution {
public:
    vector<vector<int>> rotateMat90(vector<vector<int>>& mat){
        int row = mat.size();
        int col = mat[0].size();

        vector<vector<int>>  temp;

        for(int i=0; i<col;i++){
            vector<int> temp2;
            for(int j=row - 1;j>=0;j--){
                temp2.push_back(mat[j][i]);
            }
            temp.push_back(temp2);
        }

        return temp;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        //as max rotation possible are 4
        vector<vector<int>> temp = mat;

        while(temp != target){
            temp = rotateMat90(temp);
            if(temp == mat){
                return false;
            }
        }

        return true;
    }
};