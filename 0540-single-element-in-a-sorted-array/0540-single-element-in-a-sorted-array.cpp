class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n =  nums.size();
        int start = 0;
        int end = n-1;

        int mid = (start + end)/2;

        while(start<end){
            if(mid % 2 == 1){  /////impoooortant/////
                mid--;
            }

            if(nums[mid] == nums[mid+1]){
                start = mid + 2;
            }
            else{
                end=mid;
            }
            mid = (start + end)/2;
        }
        return nums[end];
    }
};