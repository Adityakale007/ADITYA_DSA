class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int n = nums.size();
        int a = INT_MAX;
        int b = INT_MAX;
        int mini = INT_MAX;
        bool a_check = false;
        bool b_check = false;

        for(int i=0;i<n;i++){
            if(nums[i] == 1){
                a_check = true;
                a = i;
            }
            else if(nums[i] == 2){
                b_check = true;
                b = i;
            }

            if(a_check && b_check){
                mini = min(mini , abs(a-b));
            }
        }
        return mini == INT_MAX ? -1 : mini; 
    }
};