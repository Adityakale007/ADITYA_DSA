class Solution {
public:
    string removeKdigits(string nums, int k) {
        int n = nums.size();
        string ans = "";
        for(int i=0;i<n;i++){
            while((ans.size() != 0)     &&  (k>0)  &&   nums[i] < ans.back()){
                //increasing monotonic stack
                //as 1111 is better than 1112
                ans.pop_back();
                k--;
            }

            ans.push_back(nums[i]);
        }

        //if k is still left
        while(k>0){
            ans.pop_back();
            k--;
        }

        //triming zeros
        string result = "";
        for(int i=0;i<ans.size();i++){
            if(ans[i] == '0')continue;
            else{
                for(int j=i;j<ans.size();j++){
                    result += ans[j];
                }
                break;
            }
        }

        if(result.empty())return "0";

        return result;
    }
};