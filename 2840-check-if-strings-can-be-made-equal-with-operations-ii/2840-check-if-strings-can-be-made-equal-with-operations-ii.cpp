class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int> odd1;
        vector<int> odd2;
        vector<int> even1;
        vector<int> even2;
        int n = s1.size();

        for(int i=0;i<n;i++){
            if(i%2 == 0){
                even1.push_back(s1[i] - '0');
                even2.push_back(s2[i] - '0');
            }
            else{
                odd1.push_back(s1[i] - '0');
                odd2.push_back(s2[i] - '0');
            }
        }
        sort(odd1.begin(),odd1.end());
        sort(odd2.begin(),odd2.end());
        sort(even1.begin(),even1.end());
        sort(even2.begin(),even2.end());

        return ((odd1 == odd2) && (even1 == even2));
    }
};