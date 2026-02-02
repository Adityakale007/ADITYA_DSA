class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> ans;

        for(int i=0;i<n;i++){
            int dist = INT_MAX;
            for(int j=i;j<n;j++){
                if(s[j] == c){
                    dist = abs(j-i);
                    break;
                }
            }
            ans.push_back(dist);
        }


        for(int i=n-1;i>=0;i--){
            int dist = INT_MAX;
            for(int j=i;j>=0;j--){
                if(s[j] == c){
                    dist = abs(j-i);
                    break;
                }
            }
            if(ans[i] > dist){
                ans[i] = dist;
            }
        }
        return ans;
    }
};