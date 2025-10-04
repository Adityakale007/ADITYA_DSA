class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int m = bank[0].size();

        int ans = 0;
        int sum = 0;
        vector<int> temp;

        for(int i=0;i<n;i++){
            sum = 0;
            for(int j=0;j<m;j++){
                sum += (bank[i][j] - '0');
            }
            if(sum != 0)
                temp.push_back(sum);
        }
        if(temp.size() < 2)return 0;

        for(int i=0;i<temp.size() - 1;i++){
            ans = ans + (temp[i]*temp[i+1]);
        }
        return ans;
    }
};