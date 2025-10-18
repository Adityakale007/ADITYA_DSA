class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int,int> mp;

        for(int a:arr){
            mp[a]++;
        }

        vector<pair<int,int>> vec(mp.begin(), mp.end());

        sort(vec.begin(), vec.end(), [](auto &a, auto &b){
            return a.second < b.second;  // sort by value (frequency)
        });

        int cnt = 0;

        int i = 0;
        while (i < vec.size() && k > 0) {
            int freq = vec[i].second;
            if (k >= freq) {
                k -= freq;
                // Remove this element by erasing
                // vec.erase(vec.begin() + i);      // --->>. O(n) operation

                cnt++;
                i++;
                // Do not increment i, because after erasing
                // the next element shifts into current index
            } else {
                break; // can't fully remove this number
            }
        }
        
        return vec.size() - cnt;
    }
};