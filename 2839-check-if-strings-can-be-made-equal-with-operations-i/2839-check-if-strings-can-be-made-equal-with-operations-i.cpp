class Solution {
public:
    // string swapT(string s,int i,int j){
    //     char temp = s[i];
    //     s[i] = s[j];
    //     s[j] = temp;
    //     return s;
    // }
    bool canBeEqual(string s1, string s2) {
        return (    ((s1[0] == s2[0]   &&  s1[2] == s2[2])    ||
                    (s1[0] == s2[2]   &&  s1[2] == s2[0]) ) 
                    
                    &&

                    ((s1[1] == s2[1]   &&  s1[3] == s2[3])   ||
                    (s1[1] == s2[3]   &&  s1[3] == s2[1])));
    }
};