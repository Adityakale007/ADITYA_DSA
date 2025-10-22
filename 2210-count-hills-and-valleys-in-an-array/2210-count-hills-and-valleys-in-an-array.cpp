class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        
        int i = 0;
        while(i<n){
            temp.push_back(nums[i]);

            int j = i+1;
            while(j<n && nums[i] == nums[j]){
                j++;
            }
            i=j;
        }

        n = temp.size();
        int cnt = 0;

        for(int i=1;i<n-1;i++){
            if(temp[i] > temp[i-1] && temp[i] > temp[i+1]){
                cnt++;
            }
            else if(temp[i] < temp[i-1] && temp[i] < temp[i+1]){
                cnt++;
            }
        }
        return cnt;
    }
};