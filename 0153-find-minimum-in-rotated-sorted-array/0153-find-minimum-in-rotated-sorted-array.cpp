class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int start = 0;
        int end = n-1;

        int mid = (start+end)/2;

        int mini=10000;
        for(int i=0;i<n;i++){
            mini = min(mini,nums[i]);
        }

        /*while(start<=end){
            //if left sorted
            if(nums[start]<=nums[mid]){
            }
            
        }*/
        return mini;
    }
};