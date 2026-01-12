class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long long sum = 0;
        long long negCnt = 0;
        long long mini = LLONG_MAX;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] < 0)negCnt++;
                sum += abs(matrix[i][j]);

                mini = min(mini , (long long)abs(matrix[i][j]));
            }
        }

        if(negCnt % 2 != 0){
            sum -= 2*mini;
        }

        return sum;
    }
};