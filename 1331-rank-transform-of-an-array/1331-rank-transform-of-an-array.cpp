class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int>v(arr.begin(),arr.end());
        sort(v.begin(),v.end());
        int t = 1;
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            if(!mp.count(v[i])){
                mp[v[i]] = t;
                t++;
            }
        }

        for(int i=0;i<n;i++){
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};