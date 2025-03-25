class Solution {
    private:
    bool solve_TOP_DOWN(vector<int>& arr, int start,vector<int>& dp){
        int n = arr.size();
        //base case
        if(start >= n)
            return false;
        if(start < 0)
            return false;
        if(arr[start] == 0)
            return true;

        if(dp[start] != -1)
            return dp[start];

        dp[start] = 0;              //sort of backtrack
        //Without dp[start] = 0, the function can keep going back and forth indefinitely.
        //as the upper codition will become true (as dp[start] != -1(equal to 0))

        bool ans = false;
                bool add = solve_TOP_DOWN(arr,start + arr[start],dp);
                bool sub = solve_TOP_DOWN(arr,start - arr[start],dp);
            ans = add || sub ;

        return dp[start] = ans;
    }

    // bool solve_BOTTOM_UP(vector<int>& arr, int start){
    //     int n = arr.size();
    //     vector<bool> dp(n+1,false);
    //     dp[start] = 0;
    //     //add
    //     bool ans1 = false;
    //     for(int start = n;start>=0;start--){
    //         ans1 = dp[start + arr[start]];
            
    //     }
    //     //sun
    //     bool ans2 = false;
    //     for(int start = 0;start<n;start++){
    //         ans2 = dp[start - arr[start]];
    //     }
    //     bool ans =  ans1 || ans2;
    //     dp
    // }
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> dp(n+1,-1);
        return solve_TOP_DOWN(arr,start,dp);
        // return solve_BOTTOM_UP(arr,start);
    }
};