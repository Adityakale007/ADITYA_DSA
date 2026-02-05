class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
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
        return v;
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        return merge(intervals);
    }
};