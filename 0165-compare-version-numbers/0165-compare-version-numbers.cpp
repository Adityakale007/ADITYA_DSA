class Solution {
public:
    int compareVersion(string version1, string version2) {
        // int n = version1.size();
        // int m = version2.size();

        // int t1 = version1.find_first_of(".");
        // int t2 = version2.find_first_of(".");

        // string nums1 = version1.substr(t1+1,n);
        // long long number1 = stoll(nums1);
        // string nums2 = version2.substr(t2+1,m);
        // long long number2 = stoll(nums2);

        // // n = number1.size();
        // // m = number2.size();

        // if(number1 > number2){
        //     return 1;
        // }
        // else if(number1 < number2){
        //     return -1;
        // }

        // return 0;


        int n = version1.size();
        int m = version2.size();

        int i=0;
        int j=0;

        while(i<n || j<m){
            long num1 = 0,num2 = 0;

            while(i<n && version1[i] != '.'){
                num1 = num1*10 + (version1[i] - '0');
                i++;
            }
            while(j<m && version2[j] != '.'){
                num2 = num2*10 + (version2[j] - '0');
                j++;
            }

            i++;    //skip if there is "."
            j++;    //skip if there is "."

            if(num1 > num2)return 1;
            if(num1 < num2)return -1;
        }
        return 0;
    }
};