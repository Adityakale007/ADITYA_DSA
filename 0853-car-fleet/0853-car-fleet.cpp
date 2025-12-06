class Solution {
public:
    int carFleet(int target, vector<int>& p, vector<int>& s) {
        int n = p.size();

        vector<pair<int,double>> v;
        for(int i=0;i<n;i++){
            double time = (double)(target - p[i])/s[i];
            v.push_back({p[i],time});
        }

        sort(v.rbegin(),v.rend());
        //whose position is closer to the target will be calculated first

        double slowest = 0;
        int fleet = 0;
        for(auto car:v){
            double t = car.second;
            if(t > slowest){
                fleet++;
                slowest = t;
            }
        }
        return fleet;
    }
};