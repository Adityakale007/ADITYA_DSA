class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& a) {
        int n = a.size();
        long long weight = mass;
        sort(a.begin(),a.end());

        for(int i=0;i<n;i++){
            if(weight >= a[i]){
                weight += a[i];
            }
            else{
                return false;
            }
        }
        return true;
    }
};