class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int ans = 0;
        int i = 0;

        while(i<n){
            int sum = 0;
            int j=i+1;
            int maxi = neededTime[i];
            sum = neededTime[i];

            while(j<n && colors[j] == colors[i]){ //basically compairing i+1 and i
                maxi = max(maxi,neededTime[j]);
                sum += neededTime[j];
                j++;
            }
            i = j;
            ans = ans + sum - maxi; 
        }
        return ans;
    }
};