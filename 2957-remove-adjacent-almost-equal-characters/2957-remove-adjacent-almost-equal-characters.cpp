class Solution {
public:
    int removeAlmostEqualCharacters(string words) {
        int n = words.size();
        int cnt = 0;
        for(int i=1;i<n;i++){
            if((abs(words[i] - words[i-1])) <= 1){
                cnt++;
                i++;
            }
        }
        return cnt;
    }
};