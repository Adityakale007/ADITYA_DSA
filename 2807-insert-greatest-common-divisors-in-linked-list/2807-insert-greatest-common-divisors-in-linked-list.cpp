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
    int GCD(int a, int b) {
        if (b == 0)
        return a; // base case

        return GCD(b, a % b); // recursive step
    }


    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head    ||  !head->next)return head;    //if single node

        ListNode* curr = head;

        while(curr && curr->next){  //run loop till curr and curr->next exisits
            int g = GCD(curr->val,curr->next->val);
            ListNode* newNode = new ListNode(g);

            // insert between curr and curr->next
            newNode->next = curr->next;
            curr->next = newNode;

             // move to the node after the inserted one
            curr = newNode->next;
        }

        return head;
    }
};