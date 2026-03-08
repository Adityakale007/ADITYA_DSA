class Solution {
public:
    int minCost(int n) {
        return n*(n-1)/2;
        //as everytime 5 => 4,1 => 3,1,1 => 2,1,1,1 => 1,1,1,1,1
    }
};