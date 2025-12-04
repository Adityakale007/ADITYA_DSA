class Solution {
public:
    int countCollisions(string d) {
        int n = d.size();
        int collisions = 0;
        int cntL = 0;
        int cntR = 0;

        string left = d;
        string right = d;

        for(int i=0;i<n;i++){
            if(left[i] == 'R'){
                left[i] = 'S';
            }

            if(right[i] == 'L'){
                right[i] = 'S';
            }
        }

        //for right
        for(int i=0;i<n;i++){
            if(right[i] == 'R'){
                cntR++;
            }
            else if(right[i] == 'S' && cntR >= 1){
                collisions += cntR;
                cntR = 0;
            }
        }

        //for left
        for(int i=n-1;i>=0;i--){
            if(left[i] == 'L'){
                cntL++;
            }
            else if(left[i] == 'S' && cntL >= 1){
                collisions += cntL;
                cntL = 0;
            }
        }

        return collisions;
    }
};