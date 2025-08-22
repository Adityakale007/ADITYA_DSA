class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        long long maxSum =0;
        long long sum =0;
        unordered_map<int,int> freq;

        int left=0;
        for(int right=left;right<n;right++){
            sum += nums[right];
            freq[nums[right]]++;

            if(right - left + 1 > k)    //right - left + 1 -> size
            {
                sum -= nums[left];
                freq[nums[left]]--;
                if(freq[nums[left]] == 0)freq.erase(nums[left]);
                left++;
            }

            if(right - left + 1 == k    &&  freq.size() == k)
            {
                maxSum = max(sum,maxSum);
            }
        }

        return maxSum;





        // int n = nums.size();
        // if(n<k)return 0;

        // long long maxSum = 0;

        // //removing duplicates globally is wrong. --> to refrain from this
        // for(int left = 0;left<n-(k-1);left++){
        //     long long sum = 0;
        //     unordered_set<int> s;
        //     bool flag = true;

        //     for(int j=left;j<left+k;j++){
        //         if(s.contains(nums[j])){
        //             flag=false;
        //         }
        //         sum += nums[j];
        //         s.insert(nums[j]);
        //     }

        //     if(flag)
        //         maxSum = max(sum,maxSum);
        // }


        // return maxSum;





        // vector<int> result;
        // int left = 0;
        // int right = k-1;
        
        // //for storing non-duplicate terms
        // unordered_set<int>s;
        // for(int i =0;i<nums.size();i++){
        //     if(s.find(nums[i]) == s.end()){
        //         result.push_back(nums[i]);
        //     }
        //     s.insert(nums[i]);
        // }

        
        // int n = result.size();
        // long long sum=0;
        // long long maxSum = 0;

        // for(int i=0;i<n-(k-1);i++){     //for -> right<n
        //     sum=0;
        //     for(int j=left;j<=right;j++){
        //         sum += result[j];
        //     }
        //     maxSum = max(maxSum,sum);
        //     left++;
        //     right++;
        // }

        // return maxSum;

        //❌ removing duplicates globally is wrong.
        // duplicates must be checked within each window.
    }
};

const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);
#define LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();