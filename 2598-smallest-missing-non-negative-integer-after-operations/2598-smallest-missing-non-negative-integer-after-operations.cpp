class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> count(value,0);
        int n = nums.size();

        for(int i=0;i<n;i++){
            int t = (nums[i]%value + value) % value;
            count[t]++;
        }

        int result = 0;
        while(count[result % value] > 0){
            count[result % value]--;
            result++;
        }
        return result;
    }
};