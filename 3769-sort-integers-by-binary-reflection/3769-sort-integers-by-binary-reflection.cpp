class Solution {
public:
    int toBinary(int n){
        string binary = "";
        while (n > 0) {
            binary = char('0' + (n % 2)) + binary; // prepend remainder
            n /= 2;
        }
        reverse(binary.begin(),binary.end());

        int result = 0;
        for (char c : binary) {
            result = result * 2 + (c - '0');  
        }
        return result;
    }


    vector<int> sortByReflection(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int,int>> temp;
        for(int i=0;i<n;i++){
            temp.push_back({toBinary(nums[i]),nums[i]});
        }
        sort(temp.begin(),temp.end());
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i] = temp[i].second;
        }
        return ans;
    }
};