class Solution {
public:
    // bool check(int nums,double k){
    //     int root = round(pow(nums,1.0 / k)); //takes ceil function

    //     long long val = 1;
    //     for(int i=0;i<k;i++){
    //         val *= root;
    //     }
        
    //     return val == nums;
    // }

        //Hints
    //Count how many perfect kth powers are at most r, then subtract how many are less than l.
    //Be careful of edge case: k == 1.
    //Be careful of this edge case: l == 0.

    int countKthRoots(int l, int r, int k) {
        // int cnt = 0;
        // for(int i = l;i<=r;i++){
        //     if(check(i,k)){
        //         cnt++;
        //     }
        // }
        // return cnt;

        if(k == 1)return r-l+1;

        int cnt = 0;

        for(int i=0; i*i <= r;i++){ //we will atleast iterate till square value is r(for k >= 2)
            long long p = pow(i,k);
            if(p > r)break;
            if(p >= l   &&  p <= r)cnt++;
        }
        return cnt;
    }
};