class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        int m = mana.size();
        vector<long long> prefix_skills(n, 0);

        // Build prefix skills array
        for (int i = 1; i < n; i++) {
            prefix_skills[i] = prefix_skills[i - 1] + skill[i];
        }

        long long total_time = (long long)skill[0] * mana[0];

        for (int j = 1; j < m; j++) {
            long long max_time = (long long)skill[0] * mana[j];
            for (int i = 1; i < n; i++) {
                long long diff_time = prefix_skills[i] * mana[j - 1] - prefix_skills[i - 1] * mana[j];
                if (diff_time > max_time) {
                    max_time = diff_time;
                }
            }
            total_time += max_time;
        }

        return total_time + prefix_skills[n - 1] * mana[m - 1];
    }
};