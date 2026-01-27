class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        vector<int> nums;
        for(int i=1;i<=n+1;i++){
            nums.push_back(i);
        }
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        do{
            result.push_back(nums);
        }while(next_permutation(nums.begin(),nums.end()));

        int m = result.size();
        string ans = "";
        for(int i=0;i<m;i++){
            bool flag = true;
            for(int j=0;j<n;j++){
                if(!((pattern[j] == 'I' && result[i][j] < result[i][j+1])  ||
                    (pattern[j] == 'D' && result[i][j] > result[i][j+1])) ){
                        flag = false;
                        break;
                    }
            }
            if(flag){
                for(int k=0;k<=n;k++){
                    ans += to_string(result[i][k]);
                }
                return ans;
            }
        }
        return "";
    }
};