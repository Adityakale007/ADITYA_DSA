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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        // while(k>0){
        //     ListNode* curr = head;
        //     int data = 0;
        //     while(curr != NULL  &&  curr->next != NULL  &&  curr -> next -> next != NULL){
        //         curr = curr -> next;
        //     } 
        //     if(curr != NULL &&  curr->next != NULL){
        //         data = curr->next->val;
        //     }
        //     else if(curr->next == NULL){
        //         return curr;
        //     }
        //     else{
        //         return NULL;
        //     }
        //     curr -> next = NULL;
        //     ListNode* temp = new ListNode(data);
        //     temp -> next = head;
        //     k--;

        //     head = temp;
        // }
        // return head;

        //this was an O(n*k) solution


        int n = 1;
        ListNode* curr = head;
        while(curr->next != NULL){
            curr = curr -> next;
            n++;
        }

        //making  list circular
        //last element = curr
        if(n!=0)k = k%n;
        if (k == 0) return head;
        curr -> next = head;
        // 1->2->3->4->5->1->2->3->4->5

        //for finding the correct spot after k rotation
        //element shifts n-k-1 times
        ListNode* temp = head;  // 1->2->3->4->5->1->2->3->4->5
        for(int i=0;i<n-k-1;i++){   //n-k-1 => 5-2-1 = 2 -->> stops after two iterations -> i == 0,1
            temp = temp->next;
        }
        // 3->4->5->1->2->3->4->5

        ListNode* ans = temp->next;
        //ans = 4->5->1->2->3->4->5
        temp -> next = NULL;
        //ans = 4->5->1->2->3->NULL

        return ans;
    }
};