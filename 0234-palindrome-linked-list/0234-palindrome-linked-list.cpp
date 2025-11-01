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
    ListNode* reeverseLL(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *copyHead = nullptr, *copyTail = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* newNode = new ListNode(curr->val);
            if (!copyHead)
                copyHead = copyTail = newNode;  //only for 1st iteration then tail moves ahead
            else {
                copyTail->next = newNode;
                copyTail = newNode;
            }
            curr = curr->next;
        }

        ListNode* reversed = reeverseLL(copyHead);

        ListNode* p1 = head;
        ListNode* p2 = reversed;

        while (p1 && p2) {
            if (p1->val != p2->val) {
                return false;
            }

            p1 = p1->next;
            p2 = p2->next;
        }
        return true;
    }
};