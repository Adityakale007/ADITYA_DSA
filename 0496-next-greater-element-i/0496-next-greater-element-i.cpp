class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //using monotonic stack
        //in decreasing order
        int n = nums2.size();
        stack<int> s;
        vector<int>ans;
        for(int i=n-1;i>=0;i--){
            while(!s.empty()    &&  nums2[i] > s.top()){
                    s.pop();
            }

            if(s.empty()){
                ans.push_back(-1);
                s.push(nums2[i]);
            }
            else{
                //nums[i] < s.top()
                ans.push_back(s.top());
                s.push(nums2[i]);
            }
        }
        reverse(ans.begin(),ans.end());
        vector<int>ans2;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<n;j++){
                if(nums1[i] == nums2[j]){
                    ans2.push_back(ans[j]);
                    break;
                }
            }
        }
        return ans2;
    }
};