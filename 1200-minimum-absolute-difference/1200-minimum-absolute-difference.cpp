class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int diff = 0;
        int mini = INT_MAX;
        int n = arr.size();
        sort(arr.begin(),arr.end());

        for(int i=0;i<n-1;i++){
            diff = arr[i+1] - arr[i];
            mini = min(mini,diff);
        }

        vector<vector<int>> ans;
        for(int i=0;i<n-1;i++){
            if(arr[i+1] - arr[i] == mini){
                ans.push_back({arr[i] , arr[i+1]});
            }
        }

        return ans;
    }
};