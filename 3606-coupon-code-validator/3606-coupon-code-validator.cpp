class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();

        // bool one = true;
        // bool two = true;
        // bool three = true;

        vector<pair<string,string>> ans;
        vector<string> finalAns;

        for(int i=0;i<n;i++){
            bool one = true, two = true, three = true;
            bool four = false;

            int m = code[i].size();
            if(m == 0){
                one = false;
            }
            for(int j=0;j<m;j++){
                if ( (code[i][j] >= 'a' && code[i][j] <= 'z') ||
                    (code[i][j] >= 'A' && code[i][j] <= 'Z') ||
                    (code[i][j] >= '0' && code[i][j] <= '9') ||
                    code[i][j] == '_')
                {
                    continue;
                }
                else{
                    one = false;
                    break;
                }
            }



            if (businessLine[i] != "electronics" &&
                businessLine[i] != "grocery" &&
                businessLine[i] != "pharmacy" &&
                businessLine[i] != "restaurant") 
            {
                two = false;
            }



            three = isActive[i];


            if(one && two && three){
                four = true;
            }
            if(four){
                ans.push_back({businessLine[i] , code[i]});
            }
        }

        sort(ans.begin(),ans.end());

        for(auto &a:ans){
            finalAns.push_back(a.second);
        }

        return finalAns;
    }
};