class Solution {
public:
    // int solveLISusingBS(int n,string a){
    //     if(n == 0)return 0;

    //     vector<char> ans;
    //     ans.push_back(a[0]);

    //     for(int i=1;i<n;i++){
    //         if(a[i] > ans.back()){
    //             ans.push_back(a[i]);
    //         }
    //         else{
    //             //swap with just bigger element 
    //             int index = lower_bound(ans.begin(),ans.end(),a[i]) - ans.begin();
    //             ans[index] = a[i];
    //         }
    //     }
    //     return ans.size();
    // }


    bool isValid(vector<string>& strs,int n,int curr,int prev){
        for(int i=0;i<n;i++){
            if(strs[i][curr] < strs[i][prev]){
                return false;
            }
        }
        return true;
    }

    int solveLISusingTOP_DOWN(vector<string>& strs,int n,int m,int curr,int prev,vector<vector<int>>& dp){
        if(curr == m)return 0;  //we are traversing column wise
    
        if(dp[curr][prev + 1] != -1){
            return dp[curr][prev + 1];
        }

        //take
        int take = 0;
        //if(strs[curr] > strs[prev])
        if(prev == -1   || isValid(strs,n,curr,prev)){
            take = 1 + solveLISusingTOP_DOWN(strs,n,m,curr + 1,curr,dp);
        }

        //not take;
        int notTake = 0 + solveLISusingTOP_DOWN(strs,n,m,curr + 1,prev,dp);

        return dp[curr][prev+1] = max(take,notTake);
    }

    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();

        // vector<pair<string,int>>v;

        // for(int i = 0;i<n;i++){
        //     int cnt = 0;
        //     for(int j=0;j<m-1;j++){
        //         if(strs[i][j] < strs[i][j+1]){
        //             cnt++;
        //         }
        //     }

        //     v.push_back({strs[i] , cnt});
        // }

        // int minCnt = INT_MAX;
        // for(auto vec:v){
        //     minCnt = min(minCnt , vec.second);
        // } 

        // return m - minCnt - 1;


        ///////////////////////////////////////////////////////////////////////////////
        // /////<<<<<<<<< THIS IS A LARGEST INCREASING SUBSEQUENCE PROBLEM >>>>>>>>>>///////
        ///////////////////////////////////////////////////////////////////////////////

        vector<vector<int>>dp(m+1,vector<int> (m + 1,-1));

        int longest = solveLISusingTOP_DOWN(strs,n,m,0,-1,dp);
        return m - longest;
    }
};