class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        int m = num1.size(), n = num2.size();
        long long mul = 0;
        long long sum = 0;
        vector<int> temp(m+n,0);
        string ans = "";

        // Multiply each digit
        for (int j = n - 1; j >= 0; --j) {
            for (int i = m - 1; i >= 0; --i) {
                mul = ((num1[i]-'0')*(num2[j]-'0'));
                sum = mul + temp[i+j+1];
                temp[i+j+1] = sum%10;
                temp[i+j] += sum/10;
            }
        }
        for(int num : temp){
            if (!(ans.empty() && num == 0))
                ans.push_back(num + '0');
        }
        return ans.empty() ? "0" : ans;
    }
};