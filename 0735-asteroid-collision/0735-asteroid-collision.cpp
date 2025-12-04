class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        int n = a.size();
        vector<int> st;

        for(int i=0;i<n;i++){
            bool destroyed = false;

            while(!st.empty() && st.back()>0 && a[i]<0){
                if(st.back()    <   -a[i]){
                    st.pop_back();
                }
                else if(st.back()    ==   -a[i]){
                    st.pop_back();
                    destroyed = true;
                    break;
                }
                else{
                    destroyed = true;
                    break;
                }
            }

            if(!destroyed){
                st.push_back(a[i]);
            }
        }

        return st;
    }
};