class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        unordered_map<int,int>freq;
        int ans = 0;

        for(int i=0;i<n;i++){
            int need = k - nums[i];
            bool flag = false;
            if(freq.count(need)){
                // temp.push_back(need);
                ans++;
                freq[need]--;
                if(freq[need] == 0)freq.erase(need);
                flag = true;
            }

            if(!flag)freq[nums[i]]++;
        }

        return ans;
    }
};