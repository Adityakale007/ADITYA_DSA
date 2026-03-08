class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        map<int,int>m;
        for(int i=0;i<n;i++)
        {
            m[nums[i]]++;
        }
        int smallest = m.begin()->first;
        int target = m.begin()->second;

        for(auto it = next(m.begin());it != m.end() ; ++it){
            //from next as (smallest = m.begin()->first;)
            if(it->second != target){
                return {smallest,it->first};
            }
        }

        return {-1,-1};
    }
};