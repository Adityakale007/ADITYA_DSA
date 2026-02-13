class Solution {
public:
    // bool check(unordered_map<int,int>& mp){
    //     if(mp.size() == 0)return true;

    //     for(auto m:mp){
    //         if(m.second > 1)return false;
    //     }
    //     return true;
    // }


    int minLength(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int sum = 0;
        int minLength = INT_MAX;
        unordered_map<int,int>m;

        while(r<n){
            m[nums[r]]++;
            if(m[nums[r]] == 1){
                sum += nums[r];
            }

            while(sum >= k && l<=r){
                minLength = min(minLength,r-l+1);
                m[nums[l]]--;
                if(m[nums[l]] == 0){
                    sum -= nums[l];
                    m.erase(nums[l]);
                }
                l++;
            }
            r++;
        }
        return (minLength == INT_MAX ? -1 : minLength);
    }
};