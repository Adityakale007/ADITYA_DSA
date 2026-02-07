class Solution {
public:
    int minimumDeletions(string s) {
        int bCount = 0;     // number of 'b' seen so far
        int deletions = 0;  // minimum deletions till current position

        for (char c : s) {
            if (c == 'b') {
                bCount++;
            } else { // c == 'a'
                // Either delete this 'a' or delete all previous 'b's
                deletions = min(deletions + 1, bCount);
            }
        }
        return deletions;
    }
};