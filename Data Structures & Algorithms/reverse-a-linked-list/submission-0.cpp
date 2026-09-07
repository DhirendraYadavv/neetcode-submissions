class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nextTemp = curr->next; // save next node
            curr->next = prev;               // reverse pointer
            prev = curr;                     // move prev forward
            curr = nextTemp;                 // move curr forward
        }

        return prev; // prev is now the new head
    }
};