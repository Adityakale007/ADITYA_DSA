class Solution {
public:
    class compare{
        public:
        bool operator()(pair<int,int>a,pair<int,int>b){
            return a.second < b.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int>mp;
        for(int n:nums){
            mp[n]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,compare>maxHeap;
        for(auto m:mp){
            maxHeap.push({m.first,m.second});
        }
        vector<int>ans;
        while(k>0){
            pair<int,int> temp = maxHeap.top();
            maxHeap.pop();
            ans.push_back(temp.first);
            k--;
        }
        return ans;
    }
};