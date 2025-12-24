class Solution {
public:
    int minimumBoxes(vector<int>& apples, vector<int>& capacity) {
        int n = apples.size();
        int m = capacity.size();

        sort(capacity.begin(),capacity.end(),greater<int>());
        int sum = 0;
        for(int m:apples){
            sum += m;
        }

        int ans = 0;
        int cnt = 0;
        for(int m:capacity){
            if(ans < sum){
                ans += m;
                cnt++;
            }
        }
        return cnt;
    }
};