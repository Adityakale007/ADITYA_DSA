class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //solving in O(n);
        int f = 0;
        int r = 0;
        int s = 0;

        for(int i=0;i<nums.size();i++){
            f = max(f,nums[i]);
        }
        r = f;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == f){
                f = -1;
                continue;
            }
            s = max(s,nums[i]);
        }
        return (r-1)*(s-1);
    }
};