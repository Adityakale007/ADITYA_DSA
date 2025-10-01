class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        if(numBottles < numExchange)return numBottles;

        int ans = 0;
        while(numBottles >= numExchange){
            int a = numBottles/numExchange;
            ans += a * numExchange;

            numBottles = a + (numBottles - (a*numExchange));
        }
        ans += numBottles;

        return ans;
    }
};
