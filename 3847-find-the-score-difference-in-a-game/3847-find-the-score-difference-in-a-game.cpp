class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int n = nums.size();
        int first = 0;
        int second = 0;
        bool flag = nums[0]%2;

        for(int i=0;i<n;i++){
            if((i+1)%6 == 0 && i!=0)flag ^= 1;//flag change
            if(nums[i]%2 != 0 && i!=0)flag ^= 1;//flag change

            if(!flag){
                first+=nums[i];
            }
            else{
                second+=nums[i];
            }
        }

        return first - second;
    }
};