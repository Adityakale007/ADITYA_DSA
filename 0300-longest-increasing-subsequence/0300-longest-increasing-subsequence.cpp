//********************longest increasing subsequence********************//
//********************also____using binary search********************//
class Solution {
    private:
        int solve_TOP_DOWN(vector<int>& nums,int curr,int prev,vector<vector<int>>& dp){
            int n = nums.size();
            //base case
            if(curr == n)
                return 0;

            if(dp[curr][prev + 1] != -1)
                return dp[curr][prev + 1];          //prev + 1 as to compensate prev = -1

            int Take = 0;
            if(prev == -1 || nums[curr] > nums[prev]){
                Take = 1 + solve_TOP_DOWN(nums,curr + 1,curr,dp);
            }
            int NotTake = 0 + solve_TOP_DOWN(nums,curr + 1,prev,dp);

            dp[curr][prev + 1] = max(Take,NotTake);         //prev + 1 as to compensate prev = -1
            return dp[curr][prev + 1];
        }

        int solve_BOTTOM_UP(vector<int>& nums){
            int n = nums.size();
            vector<vector<int>> dp(n + 1,vector<int> (n+1,0));
            
            for(int curr = n-1;curr>=0;curr--){
                for(int prev = curr - 1;prev>=-1;prev--){
                    int Take = 0;
                    if(prev == -1 || nums[curr] > nums[prev]){
                        Take = 1 + dp[curr + 1][curr + 1];        //curr + 1 as to compensate prev = -1
                    }
                    int NotTake = 0 + dp[curr + 1][prev + 1];     //prev + 1 as to compensate prev = -1

                    dp[curr][prev + 1] = max(Take,NotTake);       //prev + 1 as to compensate prev = -1
                }
            }
            return dp[0][0];    //dp[0][-1 + 1];
        }

        int solve_SPACE_OPTIMISE(vector<int>& nums){
            int n = nums.size();
            // vector<vector<int>> dp(n + 1,vector<int> (n+1,0));
            vector<int> currRow(n+1,0);
            vector<int> nextRow(n+1,0);

            for(int curr = n-1;curr>=0;curr--){
                for(int prev = curr - 1;prev>=-1;prev--){
                    int Take = 0;
                    if(prev == -1 || nums[curr] > nums[prev]){
                        Take = 1 + nextRow[curr + 1];
                    }
                    int NotTake = 0 + nextRow[prev + 1];

                    currRow[prev + 1] = max(Take,NotTake);
                }
                //*************
                nextRow = currRow;
            }
            return nextRow[0];
        }
//********************using binary search********************//

    int solve_BINARY_SEARCH(vector<int>& nums){
        int n = nums.size();
        if(n == 0)
            return 0;
        vector<int> ans;
        ans.push_back(nums[0]);

        for(int i = 1;i<n;i++){
            if(nums[i] > ans.back()){
                ans.push_back(nums[i]);
            }
            else{
                int index = lower_bound(ans.begin(),ans.end(),nums[i]) - ans.begin();
                ans[index] = nums[i];
            }
        }
        return ans.size();
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        //curr from 0 to n-1
        //prev from -1 to n-1
        // vector<vector<int>> dp(n,vector<int> (n+1,-1));
        // return solve_TOP_DOWN(nums,0,-1,dp);
        // return solve_BOTTOM_UP(nums);
        // return solve_SPACE_OPTIMISE(nums);
        return solve_BINARY_SEARCH(nums);
    }
};