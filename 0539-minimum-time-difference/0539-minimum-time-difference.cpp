class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int>temp;

        for(int i=0;i<n;i++){
            stringstream ss(timePoints[i]);
            string a,b;
            getline(ss,a,':');
            getline(ss,b,':');
            int num1 = stoi(a);
            int num2 = stoi(b);

            if(num1 == 0 && num2 == 0){
                temp.push_back(24*60);
            }
            else{
                temp.push_back(num1 * 60 + num2);

            }
        }
        sort(temp.begin(),temp.end());
        int mini = INT_MAX;
        for(int i= 1;i<temp.size();i++){
            mini = min(mini,temp[i] - temp[i-1]);
        }
        mini = min(mini , 24*60 - (temp[n-1] - temp[0]) );

        return mini;
    }
};