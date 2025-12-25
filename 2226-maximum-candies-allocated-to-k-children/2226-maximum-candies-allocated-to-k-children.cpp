class Solution {
public:

    bool isFeasible(vector<int>& c, long long k,int x){
        //here we count students who can eat candies
        //as from one student can eat from one pile 
        //if count >= given students we return true
        long long count = 0;

        for(int i=0;i<c.size();i++){
            count += c[i]/x;
            if(count >= k)return true;
        }
        return false;
    }

    int maximumCandies(vector<int>& c, long long k) {
        // Search Space
        // Low: 1
        // High: max(candies)
        // Special case: If total candies < k → answer is 0

        long long total = 0;
        for(int x:c)total+=x;
        if(total < k)return 0;

        int low = 1;
        int high = *max_element(c.begin(),c.end());
        int ans = 0;// as we need maximum

        while(low<=high){
            int mid = low + (high - low)/2;

            if(isFeasible(c,k,mid)){
                ans = mid;
                low = mid + 1;// as we need maximum
            }
            else{
                high = mid - 1;
            }
        }
        return ans;
    }
};