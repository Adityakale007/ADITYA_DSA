class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& a) {
        sort(a.begin(),a.end());
        long long weight = mass;
        
        for(int i=0;i<a.size();i++){
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