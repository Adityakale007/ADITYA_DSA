class Solution {
public:
    int findWinningPlayer(vector<int>& s, int k) {
        int n = s.size();

        int curr = s[0];
        int index = 0;
        vector<int> temp(n);

        for(int i=1;i<n-1;i++){
            if(curr > s[i]){
                temp[index]++;
            }
            else{
                curr = s[i];
                index = i;
                temp[index]++;
            }

            if(temp[index] == k)return index;
        }
        return (max_element(s.begin(), s.end())-s.begin());
    }
};