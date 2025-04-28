bool sortByValue(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second > b.second;
}
class Solution {

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (m.count(nums[i])) {
                m[nums[i]]++;
            } else {
                m[nums[i]] = 1;
            }
        }

        // multimap<int, int> sortedMap;
        // for (auto& p : m) {
        //     sortedMap.insert({p.second, p.first});
        // }
        vector<pair<int, int>> v(m.begin(), m.end());
        sort(v.begin(), v.end(), sortByValue);

        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(v[i].first);
        }
        // sorts on basis of keys
        // vector<int> v;
        // for(auto i:sortedMap){
        //     v.push_back(i.first);
        // }
        // vector<int> ans;
        // for(int i = 0;i<k;i++){
        //     ans.push_back(v[i]);
        // }

        return ans;
    }
};