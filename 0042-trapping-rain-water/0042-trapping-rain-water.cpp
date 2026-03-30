class Solution {
public:
    int trap(vector<int>& h) {
        //int ans = min(leftMax,rightMax) - h[i]
        // also h[i] > (leftMax and rightMax both)
        int n = h.size();

        //PREFIX MAX
        vector<int> prefixMax(n);
        prefixMax[0] = h[0];
        for(int i=1;i<n;i++){
            prefixMax[i] = max(prefixMax[i-1],h[i]);
        }
        //SUFFIX MAX
        vector<int> suffixMax(n);
        suffixMax[n-1] = h[n-1];
        for(int i=n-2;i>=0;i--){
            suffixMax[i] = max(suffixMax[i+1],h[i]);
        }
        int total = 0;
        for(int i=0;i<n;i++){
            int leftMax = prefixMax[i];
            int rightMax = suffixMax[i];
            if(h[i] < leftMax   &&  h[i] < rightMax){
                total += (min(leftMax,rightMax) - h[i]);
            }
        }
        return total;
    }
};