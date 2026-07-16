class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        stringstream ss(startTime);
        int h1,m1,s1;
        char colon;
        ss >> h1 >> colon >> m1 >> colon >> s1;

        stringstream ss2(endTime);
        int h2,m2,s2;
        ss2 >> h2 >> colon >> m2 >> colon >> s2;

        int ans = 0;
        if(s2 > s1)ans+=(s2-s1);
        else if(s1>s2) {
            ans+=(60-s1+s2);
            m1++;
        }
        if(m2>m1)ans+=((m2-m1)*60);
        else if(m1>m2) {
            ans+=((60-m1+m2)*60);
            h1++;
        }

        if(h2>h1)ans+=((h2-h1)*60*60);
        else if(h1>h2) ans+=((12-h1+h2)*60*60);

        return ans;
    }
};