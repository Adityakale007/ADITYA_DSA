class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        int total = 0;
        for(int i=0;i<n;i++)total += trips[i][0];
        if(total <= capacity)return true;

        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            for(int j=trips[i][1];j<trips[i][2];j++){
                mp[j] += trips[i][0];
                if(mp[j] > capacity)return false;
            }
        }
        return true;
    }
};