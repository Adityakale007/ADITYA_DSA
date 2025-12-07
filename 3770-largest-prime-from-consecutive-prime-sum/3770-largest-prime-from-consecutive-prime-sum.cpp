class Solution {
public:
    bool isPrime(long long n){
        if(n <= 1) return false;
        if(n % 2 == 0) return n == 2;

        for(long long i = 3; i * i <= n; i += 2)
            if(n % i == 0) return false;

        return true;
    }


    int largestPrime(int n) {
        long long sum = 0;

        vector<long long> temp;

        for(int i=2;sum + i <= n;i++){
            if(isPrime(i)){
                sum += i;
                temp.push_back(sum);
            }
        }

        // no sums formed
        if(temp.empty() && isPrime(n)) return n;

        int m = temp.size();

        for(int i=m-1;i>=0;i--){
            if(isPrime(temp[i]))return temp[i];
        }

        return 0;
    }
};