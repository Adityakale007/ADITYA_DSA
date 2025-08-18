class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int currMax = nums[0];
        int currMin = nums[0];
        int maxProduct = nums[0];

        for(int i=1;i<n;i++){

            if(nums[i] < 0){
                swap(currMax, currMin); //as we will multiply by -ve number so polarity will change
            }
            //by this we can find both max on both side of number line. and if swapped then 
            //we muktiolay with nums[i] which is -ve the currMax gets updated due to swapped
            currMax = max(nums[i] , currMax*nums[i]);
            currMin = min(nums[i] , currMin*nums[i]);

            maxProduct = max(maxProduct,currMax);
        }
        return maxProduct;
    }
};