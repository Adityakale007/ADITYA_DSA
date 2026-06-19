class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi = 0;
        int altitude = 0;
        int n = gain.size();
        for(int i=0;i<n;i++){
            altitude +=  + gain[i];
            maxi = max(maxi , altitude);
        }
        return maxi;
    }
};