class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {


            ///before solveing this also check out 3sum question 
            //solution is inspired from 3sum approach


        int n = nums.size();
        int ans = nums[0] + nums[1] + nums[2];
        sort(nums.begin(),nums.end());

        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i] == nums[i-1])continue;

            for(int j=i+1;j<n-1;j++){
                if(j>i+1 && nums[j] == nums[j-1])continue;
                
                int k = j+1;
                int need = target - (nums[i] + nums[j]);
                auto it = lower_bound(nums.begin()+k , nums.end(),need);

                if(it != nums.end()){
                    int sum = nums[i] + nums[j] + *it;
                    if(abs(sum - target) < abs(ans - target)){
                        ans = sum;
                    }
                }

                //also check previous element
                if(it != nums.begin() + k){
                    it--;
                    int sum = nums[i] + nums[j] + *it;
                    if(abs(sum - target) < abs(ans - target)){
                        ans = sum;
                    }
                }
            }
        }
        return ans;
    }
};