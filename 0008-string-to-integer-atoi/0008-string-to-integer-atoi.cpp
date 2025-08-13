class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int sign = 1;
        string temp="";

        while(i<s.size() && isspace(s[i])){
            i++;
        }
        if(i<s.size() && (s[i] == '-' || s[i] == '+'))
        {
            if(s[i] == '-')
                sign = -1;
                i++;
        }
        // while(i<s.size() && ((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')))return 0;
        while (i < s.size() && s[i] == '0') i++;
        while(i<s.size() && !isdigit(s[i]))return 0;
        while(i<s.size() && isdigit(s[i])){
            temp+=s[i];
            if(temp.size()>11)break;
            i++;
        }
        if(temp.empty())return 0;
        long long num = stoll(temp) * sign;
        
        if(num > INT_MAX)return INT_MAX;
        if(num < INT_MIN)return INT_MIN;
        
        return static_cast<int>(num); 
    }     
};


