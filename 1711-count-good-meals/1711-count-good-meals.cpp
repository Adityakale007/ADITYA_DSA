class Solution {
public:
    // bool isPowerOfTwo(double n){
    //     if(n == 1)return true;
    //     if(n<1)return false;
    //     return isPowerOfTwo(n/2);
    // }


    int countPairs(vector<int>& deliciousness) {
        int n = deliciousness.size();
        const int MOD = 1e9 + 7;
        int ans = 0;
        unordered_map<int,int> freq;

        int value = 1;
        vector<int>val;
        for(int i=0;i<=21;i++){
            val.push_back(value);
            value *= 2;
        }

        for(int i=0;i<n;i++){

            for(int j=0;j<val.size();j++){
                int need = (val[j] - deliciousness[i]);

                if(freq.count(need)){
                    ans = (ans + freq[need]) % MOD;
                }
            }

            freq[deliciousness[i]]++;
        }

        return ans;
    }
};