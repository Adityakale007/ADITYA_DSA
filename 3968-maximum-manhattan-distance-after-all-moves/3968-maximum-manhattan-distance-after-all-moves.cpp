class Solution {
public:
    int maxDistance(string moves) {
        int x = 0;
        int y = 0;

        vector<int>dir(4,0);

        //make string
        for(int i=0;i<moves.size();i++)
        {
            if(moves[i] == 'L'){
                dir[0]++;
            }
            else if(moves[i] == 'R'){
                dir[1]++;
            }
            else if(moves[i] == 'U'){
                dir[2]++;
            }
            else if(moves[i] == 'D'){
                dir[3]++;
            }
        }

        int maxi = 0;
        for(int i=0;i<dir.size();i++){
            if(dir[i] > dir[maxi]){
                maxi = i;
            }
        }

        char maxChar = 'L';
        for(int i:dir){
            if(maxi == 0){
                maxChar = 'L';
            }
            else if(maxi == 1){
                maxChar = 'R';
            }
            else if(maxi == 2){
                maxChar = 'U';
            }
            else if(maxi == 3){
                maxChar = 'D';
            }
        }

        for(int i=0;i<moves.size();i++){
            if(moves[i] == '_'){
                moves[i] = maxChar;
            }
        }

        for(int i=0;i<moves.size();i++){
            if(moves[i] == 'L'){
                x--;
            }
            else if(moves[i] == 'R'){
                x++;
            }
            else if(moves[i] == 'U'){
                y++;
            }
            else if(moves[i] == 'D'){
                y--;
            }
        }
        return (abs(x) + abs(y));
    }
};