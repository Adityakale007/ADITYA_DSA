class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num<1)
        return false;

        long long left=1;
        int right=num;
        while(left<=right){
            long long mid=(left+right)/2;
            long long square= mid* mid;
            if(num>square){
                left=mid+1;
            }
            else if(num<square){
                right=mid-1;
            }
            else{

            return true;
            }
            
        }
        return false;
    }
};