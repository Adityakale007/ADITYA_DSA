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
    class compare{
        public:
        bool operator()(ListNode* a,ListNode* b){
            return a -> val > b -> val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare>minHeap; //as ascending(increasing) order

        //step 1: insert first terms of linked list in minHeap
        int n = lists.size();

        for(int i=0;i<n;i++){
            if(lists[i] != NULL){
                minHeap.push(lists[i]);
            }
        }

        ListNode* head = NULL;
        ListNode* tail = NULL;

        while(minHeap.size() > 0){
            ListNode* top = minHeap.top();
            minHeap.pop();



            if(top->next != NULL){
                minHeap.push(top->next);
            }

            if(head == NULL){
                //if Linked List is empty
                head = top;
                tail = top;
            }
            else{
                //insert at tail
                tail->next = top;
                tail = top; //increment tail
            }
        }
        return head;
    }
};