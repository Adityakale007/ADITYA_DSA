class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int maxLength = 0;

        unordered_map<int,int>odd;
        unordered_map<int,int>even;

        for(int i=0;i<n;i++){
            odd.clear();
            even.clear();
            for(int j=i;j<n;j++){
                if(nums[j] % 2 == 0){
                    even[nums[j]]++;
                }
                else{
                    odd[nums[j]]++;
                }   

                if(even.size() == odd.size()){
                    maxLength = max(maxLength , j - i + 1);
                }

            }
        }

        return maxLength;
    }
};