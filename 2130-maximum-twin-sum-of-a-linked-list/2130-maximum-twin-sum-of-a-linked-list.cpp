/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        //convert the linked list to vector
        vector<int>temp;
        ListNode* curr = head;

        while(curr){
            temp.push_back(curr->val);
            curr = curr->next;
        }

        int maxi = 0;
        int n = temp.size();

        for(int i=0;i<n;i++){
            int twinSum = temp[i] + temp[n-i-1];
            maxi = max(maxi , twinSum);
        }

        return maxi;
    }
};