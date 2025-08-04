class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
         unordered_map<int,int> map;
        int left = 0;
        int maxCount = 0;

         for(int right = 0;right<n;right++){
            map[fruits[right]]++;

            while(map.size() > 2){
                map[fruits[left]]--;
                if(map[fruits[left]] == 0){
                    map.erase(fruits[left]);
                }
                left++;
            }

            maxCount = max(maxCount , right - left + 1);
         }
         return maxCount;
    }
};