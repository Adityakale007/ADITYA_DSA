class Solution {
public:
    vector<int> nextSmallerElement(vector<int>& nums){
        int n = nums.size();
        stack<int> s;
        vector<int> ans(n,-1);

        for(int i=n-1;i>=0;i--){
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

    vector<int> prevSmaller_OrEqual_Element(vector<int>& nums){
        int n = nums.size();
        stack<int> s;
        vector<int> ans(n,-1);

        for(int i=0;i<n;i++){
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

    vector<int> nextGreaterElement(vector<int>& nums){
        int n = nums.size();
        stack<int> s;
        vector<int> ans(n,-1);

        for(int i=n-1;i>=0;i--){
            while(!s.empty()    &&  nums[i] >= nums[s.top()]){
                s.pop();
            }

            if(!s.empty()){
                ans[i] = s.top();
            }

            s.push(i);
        }
        return ans;
    }

    vector<int> prevGreater_OrEqual_Element(vector<int>& nums){
        int n = nums.size();
        stack<int> s;
        vector<int> ans(n,-1);

        for(int i=0;i<n;i++){
            while(!s.empty()    &&  nums[i] > nums[s.top()]){
                s.pop();
            }

            if(!s.empty()){
                ans[i] = s.top();
            }

            s.push(i);
        }
        return ans;
    }


    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int MOD = 1e9 + 7;
        long long ans = 0;
        vector<int> nextSmaller = nextSmallerElement(arr);
        vector<int> prevSmaller = prevSmaller_OrEqual_Element(arr);
        for(int i=0;i<n;i++){
            long long next = (nextSmaller[i] == -1)   ? n   :  nextSmaller[i];
            next = next - i;
            long long prev = prevSmaller[i];
            prev = i - prev;

            ans += arr[i] * next * prev;
        }
        return ans;
    }
    long long sumSubarrayMaxs(vector<int>& arr) {
        int n = arr.size();
        int MOD = 1e9 + 7;
        long long ans = 0;
        vector<int> nextGreater = nextGreaterElement(arr);
        vector<int> prevGreater = prevGreater_OrEqual_Element(arr);
        for(int i=0;i<n;i++){
            long long next = (nextGreater[i] == -1)   ? n   :  nextGreater[i];
            next = next - i;
            long long prev = prevGreater[i];
            prev = i - prev;

            ans += arr[i] * next * prev;
        }
        return ans;
    }




    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums)-sumSubarrayMins(nums);
    }
};