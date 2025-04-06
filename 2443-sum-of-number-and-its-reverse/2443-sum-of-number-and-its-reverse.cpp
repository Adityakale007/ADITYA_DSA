class Solution {
    int REVERSE_NUM(int num){
        int temp = num;
        int reversedNumber = 0;
        while (temp != 0) {
        int digit = temp % 10;
        reversedNumber = reversedNumber * 10 + digit;
        temp /= 10;
        }
        return reversedNumber;
    }
public:
    bool sumOfNumberAndReverse(int num) {
        string s = to_string(num);
        int n = s.length();
        if(num == 0)
            return true;
        for(int i=0; i<num; i++){
            if(i + REVERSE_NUM(i) == num)
                return true;
        }
        return false;
    }
};