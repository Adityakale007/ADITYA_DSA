class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<meetings.size();i++){
            int x = meetings[i][0];
            int y = meetings[i][1];
            int t = meetings[i][2];

            adj[x].push_back({y,t});
            adj[y].push_back({x,t});
        }

        vector<int> earlistTime(n,INT_MAX);

        // queue<int>q;
        // q.push(0);
        // q.push(firstPerson);
        //we need to use priority queue as smallest time should process first

        // min-heap: {time, person}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        pq.push({0,firstPerson});

        earlistTime[0] = 0;
        earlistTime[firstPerson] = 0;

        while(!pq.empty()){
            auto [currTime,node] = pq.top();
            pq.pop();

            // Ignore outdated states
            if (currTime > earlistTime[node]) continue;

            for(auto [neighbour,time]: adj[node]){
                if(time >= currTime    &&  earlistTime[neighbour] > time){
                    //currTime = earlistTime[node] in above condition
                    earlistTime[neighbour] = time;
                    pq.push({time,neighbour});
                }
            }
        }

        vector<int> ans;
        for(int i=0;i<earlistTime.size();i++){
            if(earlistTime[i] != INT_MAX){
                ans.push_back(i);
            }
        }

        return ans;
    }
};