class Solution {
public:
    vector<int> nextSmallerElement(vector<int>& nums){
        int n = nums.size();
        stack<int> s;
        vector<int> ans(n,-1);

        for(int i=n-1;i>=0;i--){
            while(!s.empty()    &&  nums[i] < nums[s.top()]){
                s.pop();
            }

            if(!s.empty()){
                ans[i] = s.top();
            }

            s.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerElement(vector<int>& nums){
        int n = nums.size();
        stack<int> s;
        vector<int> ans(n,-1);

        for(int i=0;i<n;i++){
            while(!s.empty()    &&  nums[i] <= nums[s.top()]){
                s.pop();
            }

            if(!s.empty()){
                ans[i] = s.top();
            }

            s.push(i);
        }
        return ans;
    }


    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int MOD = 1e9 + 7;
        int ans = 0;
        //brute force check all subarrays
        //Total number of subarrays = n * (n + 1) / 2
        // for(int i=0;i<n;i++){
        //     int mini = arr[i];
        //     for(int j=i;j<n;j++){
        //         mini = min(mini,arr[j]);
        //         ans += mini;
        //     }
        // }
        // return ans;

        //find next smaller index
        //find previous smaller index
        //then find the arrays in which the given element is small in 
        //basically find its contribution
        vector<int> nextSmaller = nextSmallerElement(arr);
        vector<int> prevSmaller = prevSmallerElement(arr);
        for(int i=0;i<n;i++){
            long long next = (nextSmaller[i] == -1)   ? n   :  nextSmaller[i];
            next = next - i;
            // int prev = (prevSmaller[i] == -1)   ? -1   ||  prevSmaller[i];
            long long prev = prevSmaller[i];
            prev = i - prev;

            ans = (ans + (arr[i] * next % MOD * prev % MOD)) % MOD;
        }
        return ans;
    }
};