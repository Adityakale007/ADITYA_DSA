class Solution {
public:
    long long flowerGame(int n, int m) {
        long long even_x = n/2;
        long long even_y = m/2;

        long long odd_x = (n+1)/2;
        long long odd_y = (m+1)/2;

        return even_x*odd_y + odd_x*even_y;
        //and -> *
        //or -> +
    }
};