class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        //eqn. of circle = (x−h)2+(y−k)2=r2 at (h,k) as centre
        int n = queries.size();
        int m = points.size();

        vector<int> ans(n);
        int count = 0;

        for(int i=0;i<n;i++){
            count = 0;
            for(int j=0;j<m;j++){

                if(((points[j][0] - queries[i][0])*(points[j][0] - queries[i][0])) + ((points[j][1] - queries[i][1])*(points[j][1] - queries[i][1])) <= ((queries[i][2])*(queries[i][2]))){
                    count++;
                }

            }
            ans[i] = count;
        }
        return ans;
    }
};