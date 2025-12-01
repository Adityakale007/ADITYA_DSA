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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ans = new ListNode(0);
        ListNode* tail = ans;
        ListNode* curr = head->next;    // skip first zero

        vector<int> vec;

        while(curr != nullptr){
            int sum = 0;

            // accumulate values until next zero
            while(curr->val != 0 && curr != nullptr){
                sum += curr->val;
                curr = curr->next;
            }
            vec.push_back(sum);

            // move past the zero node
            if(curr != nullptr){
                curr = curr->next;
            }
        }

        for(int i=0;i<vec.size();i++){
            tail->next = new ListNode(vec[i]);
            tail = tail->next;
        }

        return ans->next;//as first zero was added

    }
};