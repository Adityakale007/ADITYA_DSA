class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        vector<int>zeros;

        for(int i=0;i<n;i++){
            if(nums[i] == 0){
                zeros.push_back(i);
            }
        }

        int cnt = 0;
        int count = 0;
        
        for(int i=0;i<zeros.size();i++){
            for(int dir : {-1,1}){
                vector<int> temp = nums;
                int curr = zeros[i];    
                int d = dir;

                while(curr >= 0 && curr < n){
                    if(temp[curr] == 0){
                        curr += d;
                    }
                    else{
                        temp[curr]--;
                        d = -d;
                        curr += d;
                    }
                }

                for(int i=0;i<n;i++){
                    if(temp[i] == 0)cnt++;
                }
                if(cnt == n)count++;
                cnt = 0;
            }
        }
        return count;
    }
};