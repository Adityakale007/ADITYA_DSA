class Solution {
public:
    int maxScore(vector<int>& c, int k) {
        int n = c.size();
        int lsum = 0;
        int rsum = 0;
        for(int i=0;i<k;i++){
            lsum+=c[i];
        }

        int maxSum = lsum + rsum;

        int l=k-1;
        int r=n-1;
        while(l>=0){
            lsum -= c[l];
            l--;
            rsum += c[r];
            r--;

            maxSum = max(maxSum , lsum + rsum);
        }

        return maxSum;
    }
};