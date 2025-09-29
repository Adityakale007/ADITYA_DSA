class Solution {
public:
    int dayOfYear(string date) {
        vector<int>numbers;
        stringstream ss(date);
        string temp;

        while(getline(ss,temp,'-')){
            numbers.push_back(stoi(temp));
        }

        if(numbers[1] == 1)numbers[1] = 0;
        else if(numbers[1] == 2)numbers[1] = 31;
        else if(numbers[1] == 3)numbers[1] = 59;
        else if(numbers[1] == 4)numbers[1] = 90;
        else if(numbers[1] == 5)numbers[1] = 120;
        else if(numbers[1] == 6)numbers[1] = 151;
        else if(numbers[1] == 7)numbers[1] = 181;
        else if(numbers[1] == 8)numbers[1] = 212;
        else if(numbers[1] == 9)numbers[1] = 243;
        else if(numbers[1] == 10)numbers[1] = 273;
        else if(numbers[1] == 11)numbers[1] = 304;
        else if(numbers[1] == 12)numbers[1] = 334;

        if((numbers[0]%400 == 0)     ||      ((numbers[0]%4 == 0 )  && (numbers[0]%100 != 0))){
            if(numbers[1] == 0)numbers[1] = 0;
            else if(numbers[1] == 31)numbers[1] = 31;
            else if(numbers[1] == 59)numbers[1] = 60;
            else if(numbers[1] == 90)numbers[1] = 91;
            else if(numbers[1] == 120)numbers[1] = 121;
            else if(numbers[1] == 151)numbers[1] = 152;
            else if(numbers[1] == 181)numbers[1] = 182;
            else if(numbers[1] == 212)numbers[1] = 213;
            else if(numbers[1] == 243)numbers[1] = 244;
            else if(numbers[1] == 273)numbers[1] = 274;
            else if(numbers[1] == 304)numbers[1] = 305;
            else if(numbers[1] == 334)numbers[1] = 335;
        }

        return numbers[1]+numbers[2];
    }
};