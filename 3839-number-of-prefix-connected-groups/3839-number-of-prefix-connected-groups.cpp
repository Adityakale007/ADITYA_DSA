class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        int n = words.size();
        // int ans = 0;
        // int findex = -1;
        // int lindex = -1;
        
        // for(int i=0;i<n;i++){
        //     int cnt = 0;
        //     for(int j=i;j<n;j++){
        //         for(int z=0;z<words[j].size();z++){
        //             if(words[i][z] == words[j][z])cnt++;
        //             if(cnt == k){
        //                 ans++;
        //                 findex = i;
        //                 lindex = j;
        //                 break;
        //             }
        //         }
        //         if(cnt == k){
        //             words.erase(words.begin() + findex);
        //             words.erase(words.begin() + lindex);
        //             break;
        //         }
        //     }
        // }
        // return ans;


        //i just need map and store all the values from there and compare the prefix of k sizes
        unordered_map<string,int>m;

        for(int i=0;i<n;i++){
            if(words[i].size() < k)continue;

            string prefix = words[i].substr(0,k);
            m[prefix]++;
        }

        int ans = 0;
        for(auto mp:m){
            if(mp.second > 1){
                ans++; // as more than one is considered as group 
            }
        }
        return ans;
    }
};