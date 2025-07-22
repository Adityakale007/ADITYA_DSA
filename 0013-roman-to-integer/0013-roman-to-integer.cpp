class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> romanmap = {{'M',1000},{'D',500},{'C',100},{'L',50},
                                             {'X',10},{'V',5},{'I',1}};
         int ans = 0;
       for(int i=0;i<s.length();i++){
        if(romanmap[s[i]]<romanmap[s[i+1]]){
            ans -= romanmap[s[i]];
        }
        else{
            ans += romanmap[s[i]];
        }
       }
        return ans;
    }
};