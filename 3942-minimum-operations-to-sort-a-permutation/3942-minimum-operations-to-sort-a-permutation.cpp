class Solution {
public:
    // vector<int> reverse(vector<int>& nums){
    //     int n = nums.size();
    //     vector<int> reverse;
    //     for(int i=n-1;i>=0;i--){
    //         reverse.push_back(nums[i]);
    //     }
    //     return reversed;
    // }
    // vector<int> rotateLeft(vector<int>& nums){
    //     int n = nums.size();
    //     vector<int> rotated(n);
    //     for(int i=0;i<n;i++){
    //         rotated[i] = nums[(i + 1) % n];
    //     }
    //     return rotated;
    // }
    int minOperations(vector<int>& nums) {
        // Specifically, nums must fall into one of two categories:
        // Cyclically Increasing: [2, 3, 4, 0, 1] -> [0,1,2,3,4]
        // Cyclically Decreasing: [2, 1, 0, 4, 3] -> [4,3,2,1,0]
        // If nums is neither, it is impossible to sort, and we return -1.

        int ans = INT_MAX;
        int pos = 0;
        int n = nums.size();

        if(n == 1)return 0; //already sorted

        for(int i=0;i<n;i++){
            if(nums[i] == 0){
                pos = i;
                break;
            }
        }

        //if increaseing -> min of    -> here we will try to keep zero at first
            // -> position of zero (to rotate left) => (pos - 0)
            // -> reverse + move zero to last + (n - 1 - pos) + rotateLeft(+1) + reverse => (n - 1 - pos) + 1 + 2  => (n - pos) + 2

        

        // if decreasing -> min of      -> here we will try to keep zero at last
            // -> position of zero (to rotate left)  + 1(to rotate left) + 1(to reverse) => (pos + 2)
            // -> reverse + move zero to left start => (n - 1 - pos) + 1    => (n - pos)

        bool is_increasing = true;
        bool is_decreasing = true;

        for(int i=0;i<n;i++){
            if((nums[i] + 1) % n    !=      nums[(i + 1) % n]){
                is_increasing = false;
            }

            if((nums[i] - 1 + n) % n    !=      nums[(i + 1) % n]){
                is_decreasing = false;
            }
        }

        if(!is_increasing   &&  !is_decreasing){
            return -1;
        }


        if(is_increasing){
            ans = min({ans , pos , (n-pos) + 2});
        }

        if(is_decreasing){
            ans = min({ans , pos+2 , (n-pos)});
        }

        return ans;
    }
};