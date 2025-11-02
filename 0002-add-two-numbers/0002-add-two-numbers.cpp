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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(0);
        ListNode* curr = ans;
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        int carry = 0;

        while(curr1  ||   curr2){
            int val1 = (curr1 ? curr1->val : 0);
            int val2 = (curr2 ? curr2->val : 0);

            int sum = val1 + val2 + carry;
            carry = sum/10;
            curr->next = new ListNode(sum%10);
            curr = curr->next;

            if(curr1)curr1 = curr1->next; 
            if(curr2)curr2 = curr2->next; 
        } 

        if(carry)curr->next = new ListNode(carry);

        return ans->next;
    }
};