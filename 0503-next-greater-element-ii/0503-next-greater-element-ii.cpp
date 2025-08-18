class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1); // Default to -1 if no greater element exists
        stack<int> stack; // Stack stores indices

        for (int i = 0; i < 2*n; i++) { //traverse graph twice
            int num = nums[i%n];

            while (!stack.empty() && num > nums[stack.top()]) {
                int index = stack.top();
                stack.pop();
                result[index] = num;
            }
            if(i<n)
                stack.push(i);
        }
        
        return result;
    }
};