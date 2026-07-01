class Solution {
public:
    int numOfStrings(vector<string>& patterns, string words) {
        int n = words.size();
        int m = patterns.size();
        int ans = 0;

        for(int i=0;i<m;i++){
            int size = patterns[i].size();
            bool flag = false;
            for(int j=0;j<=n - size;j++){
                int k = 0;
                while(k < size  &&  words[j+k] == patterns[i][k]){
                    k++;
                }
                if(k == size){
                    flag = true;
                    break;
                }
            }

            if(flag){
                ans++;
            }
        }
        return ans;
    }
};