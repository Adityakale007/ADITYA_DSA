class Solution {
public:
    //north -> (0,1) as only x is to be increased
    //east -> (1,0) as only x is to be increased
    //west -> (-1,0) as only x is to be decreased
    //south -> (0,-1) as only x is to be decreased
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        //north -> east -> south -> west 
        vector<pair<int,int>>dir = {{0,1},{1,0},{0,-1},{-1,0}};

        //initializing
        int d = 0;//towards north
        int x = 0;  //at origin
        int y = 0;
        int ans = 0;


        //for obstacles
        set<pair<int,int>> hash;
        for(int i=0;i<obstacles.size();i++){
            hash.insert({obstacles[i][0],obstacles[i][1]});
        }

        for(int i=0;i<commands.size();i++){
            if(commands[i] == -1){
                //turn right
                d = (d + 1)%4; //to make it reversible
            }
            else if(commands[i] == -2){
                //turn left
                d = (d + 3)%4;
            }
            else{
                //for each point wise traverssal
                for(int j=0;j<commands[i];j++){
                    int new_X = x + dir[d].first;
                    int new_Y = y + dir[d].second;

                    if(hash.count({new_X,new_Y}))break;

                    x = new_X;
                    y = new_Y;
                    ans = max(ans,x*x + y*y);
                }
            }
        }
        return ans;
    }
};