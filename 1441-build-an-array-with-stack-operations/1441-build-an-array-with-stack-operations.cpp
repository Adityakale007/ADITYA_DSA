class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int cnt = 1;
        for(int i=0;i<target.size();i++){
            if(cnt == target[i]){
                ans.push_back("Push");
                cnt++;
            }
            else{
                while(cnt < target[i]){
                    ans.push_back("Push");
                    ans.push_back("Pop");
                    cnt++;
                }
                ans.push_back("Push");
                cnt++;
            }
        }
        return ans;
    }
};