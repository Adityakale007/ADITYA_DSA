class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();

        vector<int> ans;
        sort(potions.begin(),potions.end());
        int count = 0;

        for(int i=0;i<n;i++){
            count = 0;
            for(int j=0;j<m;j++){
                if(spells[i]*potions[j] >= success){
                    count = m - j;
                    break;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};