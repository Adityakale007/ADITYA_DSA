static bool sortByValue(const pair<int, int>& a, const pair<int, int>& b) {
    if(a.second == b.second){
        return a.first > b.first;
    }
    return a.second > b.second;
}




class Solution {
public:

    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> answer;
        int sum = 0;

        for(int i=0;i<n-k+1;i++){
                unordered_map<int,int> freq;
                for(int z=i;z<i+k;z++){
                    freq[nums[z]]++;
                }

                vector<pair<int, int>> v(freq.begin(), freq.end());
                sort(v.begin(), v.end(), sortByValue);

                int p = v.size();
                sum = 0;
                if(x<p){
                    for(int z=0;z<x;z++)
                    {
                        sum += (v[z].first*v[z].second);
                    }
                }
                else{
                    for(auto &f:v){
                        sum += (f.first*f.second);
                    }
            }

            answer.push_back(sum);
        }

        return answer;
    }
};