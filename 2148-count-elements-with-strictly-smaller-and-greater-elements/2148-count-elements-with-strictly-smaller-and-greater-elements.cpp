class Solution {
public:
    int countElements(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        map<int,int>m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        int ans = 0;
        m.erase(nums[0]);
        m.erase(nums[n-1]);
        for(auto mp:m){
            ans += (mp.second);
        }
        return ans;
    }
};