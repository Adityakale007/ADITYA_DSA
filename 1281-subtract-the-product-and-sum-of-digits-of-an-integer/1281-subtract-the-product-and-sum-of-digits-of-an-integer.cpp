class Solution {
public:
    int subtractProductAndSum(int n) {
        vector<int>digit;
        while(n>0){
            int digi = n%10;
            digit.push_back(digi);
            n /= 10;
        }

        int sum = 0;
        int product = 1;

        for(int i=0;i<digit.size();i++){
            sum += digit[i];
            product *= digit[i];
        }
        return product-sum;
    }
};