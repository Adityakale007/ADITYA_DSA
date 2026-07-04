class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        arr[0]=1;  //declare it as if not it might be possibly bigger and we can decrease it
        int ans = 1;
        for(int i=1;i<n;i++){
            if(arr[i] > arr[i-1]){
                arr[i] = arr[i-1]+1;
                ans = max(ans , arr[i]);
            }
        }
        return ans;
    }
};