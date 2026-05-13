class Solution {
public:
    static bool sortY(const vector<int>& a,const vector<int>& b){
        return a[2] > b[2];
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        int n = tasks.size();

        //sort by difference
        for(int i=0;i<n;i++){
            tasks[i].push_back(abs(tasks[i][1] - tasks[i][0]));
        }
        sort(tasks.begin(),tasks.end(),sortY);

        int ans = 0;
        int chk = 0;
        for(int i=0;i<n;i++){
            ans += tasks[i][0];
        }
        chk = ans;
        for(int i=0;i<n;i++){
            if(chk >= tasks[i][1]){
                chk -= tasks[i][0];
            }
            else{
                chk += (tasks[i][1] - chk);
                chk -= tasks[i][0];
            }
        }
        ans += chk;
        return ans;
    }
};