class Solution {
public:
    vector<int> nextSmallerElement(vector<int>& h){
        int n = h.size();
        stack<int>s;
        vector<int> ans(n,n);

        for(int i=n-1;i>=0;i--){
            //in next smaller -> we get an increasing stack
            while(!s.empty()    &&  h[i] <= h[s.top()] ){
                s.pop();
            }
            if(!s.empty()){
                ans[i] = s.top();
            }
            s.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerElement(vector<int>& h){
        int n = h.size();
        stack<int>s;
        vector<int> ans(n,-1);

        for(int i=0;i<n;i++){
            //in prev/next smaller -> we get an increasing stack
            while(!s.empty()    &&  h[i] <= h[s.top()] ){
                s.pop();
            }
            if(!s.empty()){
                ans[i] = s.top();
            }
            s.push(i);
        }
        return ans;
    }


    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        vector<int> next = nextSmallerElement(h);
        vector<int> prev = prevSmallerElement(h);
        int area = 0;

        for(int i=0;i<n;i++){
            int left = prev[i];
            int right = next[i];
            area = max(area , h[i]*(right-left-1));
        }
        return area;
    }


    int maximalRectangle(vector<vector<char>>& mat) {
        //same as histogram question
        int maxArea = 0;
        int n = mat.size();
        int m = mat[0].size();
        vector<int> preSum(m,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == '1'){
                    preSum[j] += 1;
                }
                else{
                    preSum[j] = 0;
                }
            }

            maxArea = max(maxArea , largestRectangleArea(preSum));
        }
        return maxArea;
    }
};