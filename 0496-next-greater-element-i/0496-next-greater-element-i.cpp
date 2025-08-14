class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int> result(n,-1);
        stack<int> s;

        for(int i=0;i<n;i++){
            while(!s.empty() && nums2[i] > nums2[s.top()]){
                int index = s.top();
                s.pop();

                result[index] = nums2[i];
            }
            s.push(i);
        }
        int m = nums1.size();

        vector<int> indexes;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(nums1[i] == nums2[j]){
                    indexes.push_back(j);
                }
            }
        }

        vector<int> answer(m);
        for(int i=0;i<m;i++){
            answer[i] = result[indexes[i]];
        }
        return answer;
    }
};