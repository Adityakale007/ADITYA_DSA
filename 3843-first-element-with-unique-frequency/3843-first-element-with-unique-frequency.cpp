class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }

        unordered_map<int,int>freq;

        for(auto mp:m){
            freq[mp.second]++;
        }
        int ans = -1;
        for(int i=0;i<n;i++){
            if(freq[m[nums[i]]] == 1){
                ans = nums[i];
                break;
            }
        }
        return ans;
    }
};