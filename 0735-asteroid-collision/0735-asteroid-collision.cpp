class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        int n = arr.size();
        stack<int> s;
        //collosion happens only when
        //A is going right and B is moving left
        for(int i=0;i<n;i++){
            if(arr[i] > 0){
                s.push(arr[i]);
            }
            else{//for negative element

                //collision happens when
                while(!s.empty()    &&  s.top()>0   &&  s.top() < abs(arr[i])){
                    s.pop();
                }

                //equal condition:
                if(!s.empty()   &&  s.top() == abs(arr[i])){
                    //separate as ..also can happen when s.top()<0 -> [-8,8]
                    s.pop();
                }
                else if(s.empty()   ||  s.top()<0){
                    //negative elements will push only when
                    s.push(arr[i]);
                }
            }
        }   


        vector<int>ans;
        while(!s.empty()){
            int curr = s.top();
            ans.push_back(curr);
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};