class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        unordered_map<int,int>freq;
        for(auto num:nums){
            freq[num]++;
        }

        while(true){
            vector<int>temp;
            for(auto &[num,count]:freq){
                if(count>0){
                    temp.push_back(num);
                    freq[num]--;
                }
            }
            if(temp.empty())break;
            ans.push_back(temp);
        }
        return ans;
    }
};