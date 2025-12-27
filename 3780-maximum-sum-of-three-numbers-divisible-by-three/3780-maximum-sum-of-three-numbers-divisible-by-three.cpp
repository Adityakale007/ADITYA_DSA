class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp0,temp1,temp2;

        for(int i=0;i<n;i++){
            if(nums[i]%3 == 0){
                temp0.push_back(nums[i]);
            }
            else if(nums[i]%3 == 1){
                temp1.push_back(nums[i]);
            }
            else{
                temp2.push_back(nums[i]);
            }
        }

        sort(temp0.begin(),temp0.end(),greater<int>());
        sort(temp1.begin(),temp1.end(),greater<int>());
        sort(temp2.begin(),temp2.end(),greater<int>());

        int ans = 0;
        //000
        if(temp0.size() >= 3){
            ans = max(ans,temp0[0]+temp0[1]+temp0[2]);
        }
        //111
        if(temp1.size() >= 3){
            ans = max(ans,temp1[0]+temp1[1]+temp1[2]);
        }
        // 222
        if(temp2.size() >= 3){
            ans = max(ans,temp2[0]+temp2[1]+temp2[2]);
        }
        // 012
        if(!temp0.empty() && !temp1.empty()  && !temp2.empty()){
            ans = max(ans,temp0[0]+temp1[0]+temp2[0]);
        }

        return ans;
    }
};