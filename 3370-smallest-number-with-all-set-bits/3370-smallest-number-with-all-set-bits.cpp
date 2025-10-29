class Solution {
public:
    int smallestNumber(int n) {
        string binary = "";

        while(n>0){
            binary.push_back((n%2) + '0');
            n /= 2;
        }
        reverse(binary.begin(),binary.end());

        string result = "";
        for(int i=0;i<binary.size();i++){
            result.push_back(1 + '0');
        }

        int ans = 0;

        for(int i=0;i<result.size();i++){
            ans = ans*2 + (result[i] - '0');
        }

        return ans;
    }
};