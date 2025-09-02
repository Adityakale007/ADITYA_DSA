class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int count = 0;

        //chectking every pair
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i == j)continue;
                //as it is the same point

                int Ax = points[i][0];
                int Ay = points[i][1];

                int Bx = points[j][0];
                int By = points[j][1];

                //we need to find for how many times A is on upper-left ig B
                //A is upper-left if Ax <= Bx and Ay >= By
                if(Ax<=Bx && Ay>=By)
                {
                    // count++; //as we need to check wheather ther is another point between
                    bool valid = true;

                    for(int k=0;k<n;k++){
                        if(k == i   ||  k == j)
                            continue;
                        //as if k lands on the two points itself

                        int Px = points[k][0];
                        int Py = points[k][1];

                        //check if there is any point P in between of A and B
                        if((Ax <= Px) && (Px <= Bx) && (Ay >= Py) && (Py >= By))
                        {
                            valid = false;
                            break;
                        }
                    }

                    if(valid)count++;
                }
            }
        }
        return count;
    }
};