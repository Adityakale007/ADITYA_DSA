class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size();
        int zeros = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == 0)zeros++;
        }

        int ans = 0;
        for(int i=n-1;i>=0;i--){
            if(zeros > 0    &&  nums[i] != 0){
                ans++;
            }
            else if(zeros == 0){
                break;
            }
            zeros--;
        }

        return ans;
    }
};