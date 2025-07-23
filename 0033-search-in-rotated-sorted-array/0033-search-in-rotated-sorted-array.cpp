class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int start = 0;
        int end = n - 1;

        int mid = (start + end) / 2;

        while (start <= end) {
            if (nums[mid] == target) {
                return mid;
            }
        //left half is sorted
            if(nums[start]<=nums[mid]){
                if(nums[start]<=target && target<=nums[mid]){
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }
            }
        //right half is sorted
            else{
                 if(nums[mid]<=target && target<=nums[end]){
                    start=mid+1;
                 }
                 else{
                    end=mid-1;
                 }
            }
            mid = (start + end) / 2;
        }
        return -1;
    }
};