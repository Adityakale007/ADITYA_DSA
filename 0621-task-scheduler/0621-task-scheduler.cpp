class Solution {
public:
    class compare{
        public:
        bool operator()(pair<char,int> a,pair<char,int> b){
            return a.second < b.second;
        }
    };
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>freq;
        for(int t:tasks){
            freq[t]++ ;
        }

        priority_queue<pair<char,int>,vector<pair<char,int>>,compare> maxHeap;
        for(auto m:freq){
            maxHeap.push({m.first,m.second});
        }

        int Time = 0;

        while(!maxHeap.empty()){
            int cnt = 0;
            vector<pair<char,int>> temp;
            int cycle = n+1;

            for(int i=0;i<cycle;i++){
                if(!maxHeap.empty()){
                    auto top = maxHeap.top();
                    maxHeap.pop();
                    freq[top.first]--;
                    cnt++;

                    if(freq[top.first] > 0){
                        // temp.push_back(top);     // top.second still contains old frequency
                        temp.push_back({top.first, freq[top.first]});
                    }
                }
            }

            //push remaining ones
            for(auto t:temp){
                maxHeap.push(t);
            }

            // time calculation
            if(!maxHeap.empty()){
                // after completion of a cycle
                //as one cycle size is (n+1) => (n) is the gaps and (1) is the number itself
                Time += (n+1);      // full cycle (includes idle)
            }
            else{
                Time += cnt;    // last cycle → no idle
            }
        }
        return Time;
    }
};