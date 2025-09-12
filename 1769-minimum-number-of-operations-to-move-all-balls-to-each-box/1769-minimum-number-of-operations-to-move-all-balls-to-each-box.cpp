class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();
        vector<int> answer;

        for(int i=0;i<n;i++){
            int cnt = 0;
            for(int j=0;j<n;j++){
                char ch = boxes[j];
                if(ch == '1'){
                    cnt += abs(i-j);
                }
            }
            answer.push_back(cnt);
        }
    return answer;
    }
};