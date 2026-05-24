class Solution {
public:
    int passwordStrength(string pass) {
        unordered_set<char>st;
        for(int p:pass){
            st.insert(p);
        }

        int ans = 0;

        // for(int i=0;i<st.size();i++){
        //     if(st[i] >= 'a' && st[i] <= 'z'){
        //         ans += 1;
        //     }
        //     else if(st[i] >= 'A' && st[i] <= 'Z'){
        //         ans += 2;
        //     }
        //     else if(st[i] >= '0' && st[i] <= '9'){
        //         ans += 3;
        //     }
        //     else{
        //         ans += 5;
        //     }
        // }
        // unordered_set does not support indexing like arrays or vectors.

        for(char c : st){
            if(c >= 'a' && c <= 'z'){
                ans += 1;
            }
            else if(c >= 'A' && c <= 'Z'){
                ans += 2;
            }
            else if(c >= '0' && c <= '9'){
                ans += 3;
            }
            else{
                ans += 5;
            }
        }
        return ans;
    }
};