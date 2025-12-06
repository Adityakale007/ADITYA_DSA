class Solution {
public:
    bool isBinaryPalindrome(int n){
        if(n==0)return true;

        string binary = "";
        while(n>0){
            binary = char('0' + n%2) + binary;
            n /= 2;
        }

        string revr = binary;
        reverse(revr.begin(),revr.end());

        return binary == revr;
    }

    vector<int> minOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);


        for(int i=0;i<n;i++){
            int x = 0;
            int a = nums[i];
            while(true){
                if((a-x) >= 1 && isBinaryPalindrome(a - x)){
                    ans[i] = x;
                    break;
                }
                if(isBinaryPalindrome(a + x)){
                    ans[i] = x;
                    break;
                }
                x++;
            }
        }

        return ans;
    }
};