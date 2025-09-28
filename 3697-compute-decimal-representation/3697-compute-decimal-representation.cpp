class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        int count = 0;
        int a = n;
        while(a>0){
            a /= 10;
            count++;
        }
        vector<int> ans;

        for(int i=0;i<count;i++){
            int last = n%10;
            int mul = pow(10,i);
            if(last*mul == 0){
                n /= 10;
                continue;
            }
            ans.push_back(last*mul);
            n /= 10;
        }
        reverse(ans.begin(),ans.end());

        return ans;
    }
};