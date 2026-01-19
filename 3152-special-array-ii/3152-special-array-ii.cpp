class Solution {
public:
    // bool check(vector<int>& nums){
    //     int n = nums.size();
    //     if(n == 1)return true;
    //     bool parity = nums[0]%2;

    //     for(int i=1;i<n;i++){
    //         if(nums[i]%2 == parity)return false;
    //         parity = nums[i]%2;
    //     }
    //     return true;
    // }

    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& q) {
        int n = q.size();
        int m = nums.size();
        // vector<bool>bad(m,true);
        // vector<bool>ans(n,true);
        // for(int i=0;i<m-1;i++){
        //     bad[i+1] = (nums[i]%2 == nums[i+1]%2);
        // }

        // for(int i=0;i<n;i++){
        //     //vector<int>v(nums.begin() + q[i][0],nums.begin() + q[i][1] + 1); //+1 as last wala is excluded
        //     // ans[i] = check(v);
        //     for(int j = q[i][0] + 1;j<=q[i][1];j++){
        //         if(bad[j] == true){
        //             ans[i] = false;
        //             break;
        //         }
        //     }
        // }

        // return ans;
        vector<int>badIndex;
        vector<bool>ans;
        // for(int i=0;i<m-1;i++){
        //     if(nums[i]%2 == nums[i+1]%2)
        //         badIndex.push_back(i);
        // }
        for(int i=1;i<m;i++){
            if(nums[i]%2 == nums[i-1]%2)
                badIndex.push_back(i);
        }

        for(int i=0;i<n;i++){
            int a = q[i][0];
            int b = q[i][1];

            if(a==b){
                ans.push_back(true);
                continue;
            }

            // binary search for first bad index > l
            auto it = lower_bound(badIndex.begin(),badIndex.end(),a+1);

            // check if it lies within r
            if(it != badIndex.end() && *it <= b){
                ans.push_back(false);
            }
            else{
                ans.push_back(true);
            }
        }
        return ans;
    }
};