class Solution {
public:
    class compare{
        public:
        bool operator()(pair<string,int>a,pair<string,int>b){
            if(a.second == b.second)
                return a.first > b.first;
            return a.second < b.second;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();

        unordered_map<string,int>mp;
        for(string w:words){
            mp[w]++;
        }

        priority_queue<pair<string,int>,vector<pair<string,int>>,compare>maxHeap;

        for(auto m:mp)
        {
            maxHeap.push({m.first,m.second});
        }
        vector<string>ans;
        while(k>0){
            pair<string,int> temp = maxHeap.top();
            maxHeap.pop();
            ans.push_back(temp.first);
            k--;
        }
        return ans;
    }
};