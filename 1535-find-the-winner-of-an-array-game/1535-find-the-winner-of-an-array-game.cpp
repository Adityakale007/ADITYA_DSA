class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        int curr = arr[0];
        int index = 0;
        vector<int> wins(n);

        for(int i=1;i<n;i++){
            if(curr > arr[i]){
                wins[index]++;
            }
            else{
                curr = arr[i];
                index = i;
                wins[index]++;
            }

            if(wins[index] == k)return curr;
        }
        return *max_element(arr.begin(),arr.end());
    }
};