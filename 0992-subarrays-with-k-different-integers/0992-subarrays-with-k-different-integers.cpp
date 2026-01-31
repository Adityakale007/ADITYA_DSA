class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        //brute force -> create all the subarrays
        // for(int i=0;i<n;i++){
        //     unordered_map<int,int>m;
        //     for(int j=i;j<n;j++){
        //         m[nums[j]]++;

        //         if(m.size() == k)cnt++;
        //         else if(m.size() > k)break;
        //     }
        // }


        //when a new element is added it creates a lot of sub arrays
        //no.of subarrays is equal to distance b/w r & l(r-l+1) as the previos ones are calculated earlier
        //(subarrays with <= k distinct elements) - (subarrays with <= (k-1) distinct elements)
        int l = 0;
        int r = 0;
        int cnt1 = 0;
        unordered_map<int,int>m;
        while(r<n){
            m[nums[r]]++;

            while(m.size() > k){
                m[nums[l]]--;
                if(m[nums[l]] == 0)m.erase(nums[l]);
                l++;
            }

            cnt1 += (r-l+1);

            r++;
        }

        l = 0;
        r = 0;
        int cnt2 = 0;
        m.clear();
        while(r<n){
            m[nums[r]]++;

            while(m.size() > (k-1)){
                m[nums[l]]--;
                if(m[nums[l]] == 0)m.erase(nums[l]);
                l++;
            }

            cnt2 += (r-l+1);

            r++;
        }

        cnt = cnt1 - cnt2;

        return cnt;
    }
};