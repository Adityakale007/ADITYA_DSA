class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int>nums;
        for(int i=0;i<n;i++){
            nums.push_back(nums1[i]);
        }
        for(int i=0;i<m;i++){
            nums.push_back(nums2[i]);
        }

        sort(nums.begin(),nums.end());
        n = nums.size();

        double ans = 0;
        if(n%2 != 0){
            ans = (double)nums[n/2];
        }
        else{
            ans = (double)(nums[n/2] + nums[(n/2) - 1])/(double)2;
        }

        return ans;
    }
};