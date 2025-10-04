class Solution {
public:

    string toBinary(long long n) {
        if (n == 0) return "0";

        string binary = "";
        while (n > 0) {
            binary = char('0' + (n % 2)) + binary; // prepend remainder
            n /= 2;
        }
        return binary;
    }


    string convertDateToBinary(string date) {
        stringstream ss(date);

        string year ;
        string month ;
        string day ;

        getline(ss , year , '-');       // first part
        getline(ss , month , '-');      // second part
        getline(ss , day , '-');        // third part

        long long year_num = stoll(year);
        long long month_num = stoll(month);
        long long day_num = stoll(day);

        year = toBinary(year_num);
        month = toBinary(month_num);
        day = toBinary(day_num);

        stringstream ans ;
        ans<<year<<"-"<<month<<"-"<<day;

        string answer = ans.str();

        return answer;
    }
};