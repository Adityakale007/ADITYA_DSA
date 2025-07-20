class Solution {
public:
    bool isPalindrome(int x) {
        int original=x;
        int temp=x;
        int rev=0;
        if (temp==0){
            return true;
        }
        while(temp>0){
            int digit=temp%10;
            if ((rev > (INT_MAX / 10)) ||
                (rev < (INT_MIN / 10)))
            {

                return 0;
                
            }
            rev = rev*10 + digit;
            temp=temp/10;
        }
        if(rev==original){
            return true;
        }
return false;
    }
};