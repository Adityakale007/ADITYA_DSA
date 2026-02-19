class Solution {
public:
    // bool check(vector<int>& v){
    //     if(v.size() == 0)return false;
    //     if(v.size() % 2)return false;
    //     int cnt0 = 0;
    //     int cnt1 = 0;
    //     bool flag = false;


    //     return cnt1 == cnt0;
    // }
    int countBinarySubstrings(string s) {
        int n = s.size();
        // int cnt = 0;

        // for(int i=0;i<n;i++){
        //     vector<int>v;
        //     for(int j=i;j<n;j++){
        //         v.push_back(s[j] - '0');

        //         if(check(v)){
        //             cnt++;
        //         }

        //     }
        // }

        // return cnt;

        //read dicussion and got a trick that => ans = min() + min().....
        vector<int>v;
        char flag = 1;
        for(int i=0;i<n;i++){
            if((s[i]-'0') == flag){
                if(v.size() == 0){
                    v.push_back(1);
                }
                else{
                    v.back()++;
                }
            }
            else{
                flag = (s[i]-'0');
                v.push_back(1);
            }
        }

        int ans = 0;
        for(int i=1;i<v.size();i++){
            ans += min(v[i] , v[i-1]);
        }

        return ans;
    }
};
