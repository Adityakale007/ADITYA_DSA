class Solution {
public:
    int nextGreaterElement(int n) {
        string str = to_string(n);
        string check = str ;
        vector<string> temp;

        sort(str.begin(),str.end());
        do{
            temp.push_back(str);
        }while(next_permutation(str.begin(),str.end()));

        sort(temp.begin(),temp.end());

        int i=0;
        while(i<temp.size() && temp[i] != check){
            i++;
        }

        if(i==temp.size()-1 || i==temp.size())return -1; //it it is the greatest element possible

        long long answer = stoll(temp[i+1]);
        if(answer>INT_MAX)return -1;
        return (int)answer;
    }
};