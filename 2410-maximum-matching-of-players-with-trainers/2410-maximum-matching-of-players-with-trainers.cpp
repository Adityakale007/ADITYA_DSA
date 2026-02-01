class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(trainers.begin(),trainers.end());
        sort(players.begin(),players.end());
        int n = players.size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            auto it = lower_bound(trainers.begin(),trainers.end(),players[i]);
            if(it != trainers.end()){
                cnt++;
                // int index = it - trainers.begin();
                // trainers[index] = 0;
                trainers.erase(it);
                if(trainers.size() == 0)return cnt;
            }
        }

        return cnt;
    }
};