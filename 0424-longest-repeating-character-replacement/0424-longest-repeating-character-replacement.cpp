class Solution {
public:
//     int getMinFreq(const unordered_map<char,int>& mp) {
//     int minFreq = INT_MAX;

//     for (const auto& p : mp) {
//         minFreq = min(minFreq, p.second);
//     }
//     return minFreq;
// }



    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxLength = 0;

        // for(int i=0;i<n;i++){
        //     unordered_map<char,int>m;
        //     int maxF = 0;
        //     for(int j=i;j<n;j++){
        //         m[s[j]]++;
        //         maxF = max(maxF , m[s[j]]);
        //         // int minFreq = getMinFreq(m);
        //         // if(minFreq <= k){
        //         //     maxLength = max(maxLength , j-i+1);
        //         // }

        //         //try =>> lengthOfSubstring - maxFrequency
        //         int changes = (j-i+1) - maxF;  //this many characters I need to change

        //         if(changes <= k){
        //             maxLength = max(maxLength , j-i+1);
        //         }
        //         else{
        //             break;
        //         }
        //     }
        // }



        int l = 0;
        int r = 0;
        int maxF = 0;
        unordered_map<char,int>m;
        while(r<n){
            m[s[r]]++;
            maxF = max(maxF,m[s[r]]);

            int changes = (r-l+1) - maxF;

            if(changes <= k){
                maxLength = max(maxLength , r-l+1);
            }
            else{
                m[s[l]]--;
                if(m[s[l]] == 0)m.erase(s[l]);
                l++;
            }
            r++;
        }


        return maxLength;
    }
};