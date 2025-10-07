class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();

        unordered_map<int, int> freq;
        for (int num : rains) {
            freq[num]++;
        }

        int maxi = 0;
        int zero_cnt = 0;
        int same = 0;
        bool flag = false;
        int cnt = 0;

        // for(int i=0;i<n;i++){
        //     if(rains[i]>0){
        //         if(cnt == 2 &&  !flag)return {};
        //     }
        //     if(rains[i] == 0){
        //         flag = true;
        //         cnt++;
        //     }
        // }

        for (auto& i : freq) {
            maxi = max(maxi, i.second);

            if (i.second > 1 && i.first != 0) {
                same += i.second - 1;
            }
            if (i.first == 0) {
                zero_cnt = i.second;
            }
        }

        if (maxi == 1)
            return vector<int>(n, -1);
        if (same > zero_cnt)
            return {};

        vector<int> temp;

        vector<int> ans(n, 1);             // default 1 for unused dry days
        unordered_map<int,int> full;       // lake -> last day index it was filled
        set<int> dryDays;                  // indices of days with rains[i]==0

        for (int i = 0; i < n; ++i) {
            if (rains[i] == 0) {
                dryDays.insert(i); // available dry day
            } else {
                int lake = rains[i];
                ans[i] = -1; // raining day

                if (full.count(lake)) {
                    auto it = dryDays.lower_bound(full[lake]);
                    if (it == dryDays.end()) {
                        return {}; // no available dry day -> impossible
                    }
                    ans[*it] = lake;   // dry that lake on that day
                    dryDays.erase(it); // consume that dry day
                }
                full[lake] = i; // mark lake as filled at day i
            }
        }

        return ans;
    }
};
