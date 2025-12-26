class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int ans = 0;

        int suffixSum = 0;
        for(int c=0;c<n;c++){
            if(customers[c] == 'Y'){
                suffixSum ++;
            }
        }
        int prefixSum = 0;
        int total = 0;
        int finalTotal = INT_MAX;

        for(int i=0;i<=n;i++){

            total = prefixSum + suffixSum;
            if(finalTotal > total){
                finalTotal = total;
                ans = i;
            }

            if(customers[i] == 'N'){
                prefixSum++;
            }
            else{
                suffixSum--;
            }
        }
        return ans;
    }
};