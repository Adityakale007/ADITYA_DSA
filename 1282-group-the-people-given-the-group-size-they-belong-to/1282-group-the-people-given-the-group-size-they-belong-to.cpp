class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<vector<int>> temp;

        set<int> nums(groupSizes.begin(),groupSizes.end());

        for(int s:nums){
            vector<int> temp2;
            for(int j=0;j<n;j++){
                if(s == groupSizes[j]){
                    temp2.push_back(j);
                }
            }
            
            for(int i = 0; i < temp2.size(); i += s){
                vector<int> group(temp2.begin() + i, temp2.begin() + i + s);
                temp.push_back(group);
            }
        }
        return temp;
    }
};