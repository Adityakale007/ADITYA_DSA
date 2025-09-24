class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        string result;
        
        // Handle sign
        if ((numerator < 0) ^ (denominator < 0)) result += "-";
        
        // Work with long long to prevent overflow
        long long n = llabs((long long)numerator);
        long long d = llabs((long long)denominator);
        
        // Integer part
        result += to_string(n / d);
        long long remainder = n % d;
        if (remainder == 0) return result; // No fraction part
        
        result += ".";
        
        // Store remainder positions
        unordered_map<long long, int> remainderPos;
        
        while (remainder != 0) {
            if (remainderPos.count(remainder)) {
                // Insert parentheses for repeating part
                result.insert(remainderPos[remainder], "(");
                result += ")";
                break;
            }
            remainderPos[remainder] = result.size();
            remainder *= 10;
            result += to_string(remainder / d);
            remainder %= d;
        }
        
        return result;
    }
};
