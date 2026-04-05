class Solution {
public:
    char reversed(char x){
        char t;
        if(x >= 'a' && x <= 'z'){
            t = 'z' - (x - 'a');
        }
        else{
            int num = x - '0';
            num = 9 - num;
            t = num + '0';
        }
        return t;
    }

    int mirrorFrequency(string s) {
        unordered_map<char,int>mp;
        // vector<char>v(26);
        // char t = 'a';
        // for(int i=0;i<26;i++){
        //     v[i] = 'a' + i;
        // }
        int n = s.size();

        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }

        unordered_map<char,int>used;
        int sum = 0;
        for(auto m:mp){
            char c = m.first;
            char mirror = reversed(m.first);
            if(used.count(m.first))continue;

            int freqC = m.second;
            int freqM = mp.count(mirror) ? mp[mirror] : 0;
            
            sum += abs(freqC - freqM);

            used[c]++;
            used[mirror]++;
        }
        return sum;
    }
};