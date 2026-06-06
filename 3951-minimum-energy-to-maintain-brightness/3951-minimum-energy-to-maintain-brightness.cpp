class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        //here brightness is the required amount of brightness
        int m = intervals.size();

        //first of all merge intervals
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<m-1;i++){
            if(intervals[i][1]  >=  intervals[i+1][0]){
                intervals[i+1][0] = intervals[i][0];
                if(intervals[i][1] >= intervals[i+1][1])intervals[i+1][1] = intervals[i][1];

                intervals[i][0] = -1;
                intervals[i][1] = -1;
            }
        }

        sort(intervals.begin(),intervals.end(),[](const vector<int> &a,const vector<int> &b){
            return a[1] < b[1];
        }); 
        long long totalTime = 0;
        for(int i=0;i<m;i++){
            if(intervals[i][0] == -1 &&  intervals[i][1] == -1)continue;

            totalTime += (intervals[i][1] - intervals[i][0] + 1); //+1 as both intervals are inclusive -> like r-l+1
        }

        //now maths
        //to on n bulbs we require ceil(n/3) bulbs 
        // -> as if one bulb is on it lights atmost 3 bulbs
        // eg : n=5. 00000 -> 10010 -> 11111    ->  2
        // eg : n=11. 00000000000 ->  -> 01001001001 -> 11111111111 ->  4
        
        
        long long required = ceil(brightness/3.0);
        return (long long)required * totalTime;
    }
};