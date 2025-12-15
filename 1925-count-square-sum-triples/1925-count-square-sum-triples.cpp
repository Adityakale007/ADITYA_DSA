class Solution {
public:
    bool isInt(double n){
        return floor(n) == n;
    }

    int countTriples(int n) {
        int cnt = 0;
        for(int i=1;i<n;i++){
            for(int j=1;j<n;j++){
                double target = i*i + j*j;
                double final = sqrt(target);

                if(isInt(final) && final<=n){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};