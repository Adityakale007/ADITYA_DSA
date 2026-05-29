class Solution {
public:
    int minElement(vector<int>& nums) {
        //string and stringstream question
        int sum = 0;
        int n = nums.size();

        for(int i=0;i<n;i++){
            string s = to_string(nums[i]);
            int m = s.size();
            int sum = 0;
            for(int j=0;j<m;j++){
                sum += (s[j] - '0');
            }
            nums[i] = sum;
        }
        sort(nums.begin(),nums.end());
        return nums[0];
    }
};