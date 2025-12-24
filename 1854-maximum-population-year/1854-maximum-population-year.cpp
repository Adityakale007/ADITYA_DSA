class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int n = logs.size();
        int ans = 0;
        int ansYear = 0;

        for(int year=1950;year<=2050;year++){
            int cnt = 0;
            
            for(int i=0;i<n;i++){
                if(year >= logs[i][0] && year < logs[i][1]){
                    cnt++;
                }
            }

            if(cnt > ans){
                ans = cnt;
                ansYear = year;
            }
        }
        return ansYear;
    }
};