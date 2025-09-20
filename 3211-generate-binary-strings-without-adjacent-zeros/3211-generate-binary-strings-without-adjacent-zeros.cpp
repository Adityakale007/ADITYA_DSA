class Solution {
public:
    vector<string> validStrings(int n) {

        if(n==1)
        return {"0","1"};

        vector<string> ans;
        string temp = "";


        for(int i=1;i<=n;i++){
            int cnt_1 = i;
            int cnt_0 = n - i;

            for(int j=0;j<cnt_0;j++){
                temp += "0"; 
            }
            for(int j=0;j<cnt_1;j++){
                temp += "1"; 
            }
            

            do{
                if(!temp.contains("00")){
                    ans.push_back(temp);
                }
            }while(next_permutation(temp.begin(),temp.end()));

            temp = "";
        }
        return ans;
    }
};