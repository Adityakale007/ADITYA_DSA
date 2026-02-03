class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int x = t.size();

        int minLength = INT_MAX;
        int startIndex = -1;

        //brute force -> generate all the substrings O(N2)
        //store all the occurrence(positively) of 't' in hash map 
        //and traverse 's' and add to hash map (negatively) 

        // for(int i=0;i<n;i++){
        //     vector<int>hash(256,0);

        //     for(int j=0;j<x;j++){
        //         hash[t[j]]++;
        //     }
            
        //     int cnt = 0;

        //     for(int j=i;j<n;j++){
        //         if(hash[s[j]] > 0){
        //             cnt++;
        //         } //preadded by string t
        //         hash[s[j]]--;

        //         if(cnt == x){
        //             if(j-i+1 < minLength){
        //                 minLength = j-i+1;
        //                 startIndex = i;
        //                 break;
        //             }
        //         }
        //     }
        // }


        int l = 0;
        int r = 0;
        unordered_map<char,int>m;
        int cnt = 0;

        for(int i=0;i<x;i++){
            m[t[i]]++;
        }

        while(r<n){
            if(m[s[r]] > 0){
                cnt++;
            }
            m[s[r]]--;

            while(cnt == x){
                if(minLength > r-l+1){
                    minLength = r-l+1;
                    startIndex = l;
                }

                m[s[l]]++;
                if(m[s[l]] > 0){
                    cnt--;
                }
                l++;
            }
            r++;
        }



        if (startIndex == -1) return "";
        string ans = s.substr(startIndex , minLength);
        return ans;
    }
};