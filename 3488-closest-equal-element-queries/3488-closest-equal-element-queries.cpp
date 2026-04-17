class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> ans;

        for (int i = 0; i < queries.size(); i++) {
            if (mp[nums[queries[i]]].size() == 1) {
                ans.push_back(-1);
                continue;
            }
            // for(int j=0;j<mp[nums[queries[i]]].size();j++){
            //     int a = mp[nums[queries[i]]][j];
            //     int b = queries[i];
            //     if(a == b)continue;

            //     d = min(d,abs(a-b));

            //     if(a>b){
            //         b += n;
            //         d = min(d,b-a);
            //     }
            //     else{
            //         a += n;
            //         d = min(d,a-b);
            //     }
            // }
            // ans.push_back(d);

            auto& v = mp[nums[queries[i]]];
            int m = v.size();
            // as vectoris already sorted
            // we can use lowerbound as
            // we only need to find the close ones to left and to right
            int index = lower_bound(v.begin(), v.end(), queries[i]) - v.begin();

            int left = v[(index - 1 + m) % m];
            int right = v[(index + 1) % m];

            // d = min(d, abs(queries[i] - left));
            // d = min(d, abs(queries[i] - right));
            // //as circular
            // d = min(d, abs(n - d));

            // You’re effectively doing:
            // min( min(dist1, dist2), n - min(dist1, dist2) )
            // But correct is:
            // min( min(dist1, n - dist1), min(dist2, n - dist2) )

            int dist1 = abs(queries[i] - left);
            int dist2 = abs(queries[i] - right);

            // for circular
            dist1 = min(dist1, n - dist1);
            dist2 = min(dist2, n - dist2);

            ans.push_back(min(dist1, dist2));
        }

        return ans;
    }
};