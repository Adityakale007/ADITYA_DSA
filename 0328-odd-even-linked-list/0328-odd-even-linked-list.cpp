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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* even = new ListNode(0);
        ListNode* odd = new ListNode(0);
        ListNode* oddHead = odd;
        ListNode* evenHead = even;

        ListNode* curr = head;
        bool flag = false;

        while(curr != NULL){
            if(!flag){
                int data = curr -> val;
                ListNode* temp = new ListNode(data);
                oddHead -> next = temp;
                oddHead = oddHead->next;
            }
            else{
                int data = curr -> val;
                ListNode* temp = new ListNode(data);
                evenHead -> next = temp;
                evenHead = evenHead->next;
            }

            flag = !flag;
            curr = curr->next;
        }

        ListNode* ans = oddHead;
        ans -> next = even -> next; //as both start with (0)

        return odd->next;

        // oddHead->next = even->next;
        // return odd->next;
    }
};