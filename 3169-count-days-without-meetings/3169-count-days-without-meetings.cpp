class Solution {
public:
    int countDays(int days, vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end(),[](vector<int>a,vector<int>b){
            return a[0]<b[0];
        });

        int n = nums.size();
        vector<vector<int>>v;
        for(int i=0;i<n;i++){
            int start = nums[i][0];
            int last = nums[i][1];
            for(int j=i+1;j<n;j++){
                if(last >= nums[j][0]){
                    last = max(last , nums[j][1]);
                    i = j;
                }
                else{
                    break;
                }
            }
            v.push_back({start,last});
        }

        if (v.empty()) return days;

        int cnt = v[0][0] - 1;
        n = v.size();

        for(int i=0;i<n-1;i++){
            cnt += (v[i+1][0] - v[i][1]) - 1;
        }

        cnt += days - v[n-1][1];

        return cnt;
    }
};