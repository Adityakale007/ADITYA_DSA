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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> toRemove(nums.begin(),nums.end());

        ListNode* ans = new ListNode(0);
        ListNode* tail = ans;
        ListNode* curr = head;


        while(curr){
            if(toRemove.find(curr->val) == toRemove.end()){
                tail->next = new ListNode(curr->val);
                tail = tail->next;
            }
            curr = curr->next;
        }

        return ans->next;
    }
};