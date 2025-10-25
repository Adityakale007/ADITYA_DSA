class Solution {
public:
    int totalMoney(int n) {
        int operations = n / 7;
        int sum = 0;
        int addi = 28;
        int cnt = 0;

        for (int i = 0; i < operations; i++) {
            sum += addi;
            addi += 7;
            cnt++;
        }

        operations = n % 7;

        for (int i = 1; i <= operations; i++) {
            sum = sum + i + cnt;
        }

        return sum;
    }
};
