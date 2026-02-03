class Solution {
public:

    bool isstrictlyIncreasing(vector<int>& nums,int start,int end){
        for(int i=start;i<end;i++){
            if(nums[i]>=nums[i+1])
                return false;
        }
        return true;
    }

    bool isstrictlyDecreasing(vector<int>& nums,int start,int end){
        for(int i=start;i<end;i++){
            if(nums[i]<=nums[i+1])
                return false;
        }
        return true;
    }
    
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        for(int p=1;p<n-2;p++){
            if(!isstrictlyIncreasing(nums,0,p))
                continue;

            for(int q=p+1;q<n-1;q++){
                if(!isstrictlyDecreasing(nums,p,q))
                    continue;

                if(isstrictlyIncreasing(nums,q,n-1)){
                    return true;
                }
            }
        }
        return false;
    }
};