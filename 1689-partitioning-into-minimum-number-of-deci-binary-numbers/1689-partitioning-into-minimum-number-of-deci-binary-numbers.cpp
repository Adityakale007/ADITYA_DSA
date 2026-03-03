class Solution {
public:
    int minPartitions(string n) {
        int ans = 0;
        for(int i = 0;i<n.length();i++){
                ans = max(ans , n[i] - '0');    
// Each deci-binary number can only contribute either 1 at a position OR 0 at a position .
// So if a digit is 8 that means
// You need 8 different deci-binary numbers contributing 1 in that column. hence largest number is the answer .
        }
        return ans;
    }
};