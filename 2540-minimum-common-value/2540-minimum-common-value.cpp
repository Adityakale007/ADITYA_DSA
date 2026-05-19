class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        for(int i=0;i<n;i++){
            int target = nums1[i];
            auto it = lower_bound(nums2.begin(),nums2.end(),target);
            if(it != nums2.end()    &&  *it == target){
                return *it;
            }
        }
        return -1;
    }
};