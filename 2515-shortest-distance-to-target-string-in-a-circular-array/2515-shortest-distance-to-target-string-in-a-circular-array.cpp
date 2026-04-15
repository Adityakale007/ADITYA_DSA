class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int stepsF = INT_MAX;
        int stepsB = INT_MAX;
        int steps = 1;
        int n = words.size();

        if(words[startIndex] == target){
                return 0;
            }

        int next = (startIndex + 1)%n;
        int prev = (startIndex - 1 + n)%n;

        while(next != startIndex){
            if(words[next] == target){
                stepsF = min(stepsF,steps);
            }
            next = (next + 1)%n;
            steps++;
        }

        steps = 1;

        while(prev != startIndex){
            if(words[prev] == target){
                stepsB = min(stepsB,steps);
            }
            prev = (prev - 1 + n)%n;
            steps++;
        }

        int ans = min(stepsF,stepsB);

        return ans != INT_MAX ? ans : -1;
    }
};