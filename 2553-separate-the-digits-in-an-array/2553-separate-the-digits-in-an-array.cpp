class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            vector<int> temp;
            int a = nums[i];

            while(a > 0){
                temp.push_back(a%10);
                a /= 10;
            }

            for(int i = temp.size()-1;i>=0;i--)
            {
                ans.push_back(temp[i]);
            }
        }
        return ans;
    }
};