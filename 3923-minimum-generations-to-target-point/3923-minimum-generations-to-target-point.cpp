class Solution {
public:
    // bool check(vector<vector<int>>& points, vector<int>& target){
    //     auto it = lower_bound(points.begin(), points.end(), target);
    //     if(it != points.end() && *it == target){
    //         return true;
    //     }
    //     return false;
    // }

    int minGenerations(vector<vector<int>>& points, vector<int>& target) {

        int n = points.size();

        set<vector<int>> st;
        // used set as i was doing constant sorting and O(logN) binary search in nested loops

        for (auto& p : points) {
            st.insert(p);
        }

        if (st.count(target)) {
            return 0;
        }

        // sort(points.begin(), points.end());
        // target already exists
        // if(check(points, target))
        //     return 0;

        // cannot form new points
        if (n < 2)
            return -1;

        int k = 0;

        while (true) {

            // sort(points.begin(), points.end());

            int oldSize = points.size();
            bool flag = false;

            vector<vector<int>> newPoints;

            for (int i = 0; i < oldSize; i++) {

                vector<int> a = points[i];

                for (int j = i + 1; j < oldSize; j++) {

                    vector<int> b = points[j];

                    // if( (abs(a[0] - b[0]) >= 2)     &&
                    //     (abs(a[1] - b[1]) >= 2)     &&
                    //     (abs(a[2] - b[2]) >= 2))

                    // distinct points only
                    if (a == b)
                        continue;

                    vector<int> c(3);

                    c[0] = (a[0] + b[0]) / 2;
                    c[1] = (a[1] + b[1]) / 2;
                    c[2] = (a[2] + b[2]) / 2;

                    // keep vector sorted before binary search  ################
                    // if(!check(points, c) && !check(newPoints, c)){

                    if (st.count(c))
                        continue; // using this no check function
                    // O(N) -> O(logN)

                    st.insert(c);
                    newPoints.push_back(c);

                    flag = true;

                    if (c == target) // crucial line    *********
                        return k + 1;
                }
            }

            if (!flag)
                return -1;

            // add all new points after current generation
            for (auto& p : newPoints)
                points.push_back(p);

            // sort(points.begin(), points.end());

            k++;
        }

        return -1;
    }
};