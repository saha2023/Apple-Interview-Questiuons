class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL, *curr = head;

        while(curr){
            ListNode *forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw; 
        }
        return prev;
    }
};