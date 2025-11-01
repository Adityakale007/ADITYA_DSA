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

    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;     //if single node;

        ListNode* curr = head;
        ListNode* prev = nullptr;

        while(curr != nullptr){
            ListNode* nextNode = curr->next;    //saving the next node
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode* curr = head;
        ListNode* copyHead = nullptr;
        ListNode* copyTail = nullptr;
        int cnt = 1;

        while(cnt < left    &&  curr){
            curr = curr->next;
            cnt++;
        }

        ListNode* temp = curr;
        while(cnt <= right   &&  temp){
            ListNode* newNode = new ListNode(temp->val);

            if(!copyHead){
                copyHead = copyTail = newNode;
            }
            else{
                copyTail->next = newNode;
                copyTail = newNode;
            }
            temp = temp->next;
            cnt++;
        }

        ListNode* reversed = reverseList(copyHead);

        ListNode* beforeLeft = nullptr;
        ListNode* afterRight = temp;

        curr = head;
        cnt = 1;
        while(cnt < left    &&  curr){
            beforeLeft = curr;
            curr = curr->next;
            cnt++;
        }

        if(beforeLeft){
            beforeLeft->next = reversed;
        }
        else{
            head = reversed;  //if(left = 1)
        }

        ListNode* end = reversed;
        while(end->next){
            end = end->next;
        }
        end->next = afterRight;

        return head;
    }
};