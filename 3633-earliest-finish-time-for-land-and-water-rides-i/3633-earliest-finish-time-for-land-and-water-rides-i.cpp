class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();

        int ans = INT_MAX;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                //first land then water
                int time1 = landStartTime[i] + landDuration[i];
                int next1 = max(time1 , waterStartTime[j]);
                int ans1 = next1 + waterDuration[j];

                //first water then land
                int time2 = waterStartTime[j] + waterDuration[j];
                int next2 = max(time2 , landStartTime[i]);
                int ans2 = next2 + landDuration[i];


                ans = min({ans , ans1 , ans2});
            }
        }
        return ans;
    }
};