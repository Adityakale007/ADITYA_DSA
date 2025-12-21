class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        int ans = 0;

        vector<bool> sorted(n-1 , false);   //to handle eqUAL cases other wise my last code was write

        for(int j=0;j<m;j++){
            bool detect = false;

            for(int i=0;i<n-1;i++){
                if(!sorted[i] && strs[i][j] > strs[i+1][j]){
                    detect = true;
                    break;
                }
            }

            if(detect){
                ans++;
                continue; 
                //as if it voilets the rule the column is deleted no need to change sorted according to this deleted column
            }

            for(int i=0;i<n-1;i++){
                if(!sorted[i] && strs[i][j] < strs[i+1][j]){
                    sorted[i] = true;
                }
            }
        }

        return ans;
    }
};