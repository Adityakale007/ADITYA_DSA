class Solution {
public:
    long long maxPoints(vector<int>& t1, vector<int>& t2, int k) {
        int n = t1.size();

        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({t1[i],t2[i]});
        }

        long long sum1 = 0;
        vector<int> gain(n);

        for(int i=0;i<n;i++){
            sum1 += v[i].first;
            gain[i] = v[i].first - v[i].second;
        }

        sort(gain.begin(),gain.end());

        int switches = n - k;

        for(int i=0;i<switches;i++){
            if(gain[i] > 0)break;

            sum1 -= gain[i];
        }
        return sum1;
    }
};