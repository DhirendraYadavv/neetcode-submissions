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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Dummy node acts as a placeholder to simplify edge cases
        // (like when the merged list is empty at the start).
        ListNode dummy(-1);

        // "tail" always points to the last node of the merged list so far.
        ListNode* tail = &dummy;

        // Traverse both lists as long as neither is exhausted.
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                // list1's current node is smaller (or equal) -> attach it
                tail->next = list1;
                list1 = list1->next;
            } else {
                // list2's current node is smaller -> attach it instead
                tail->next = list2;
                list2 = list2->next;
            }
            // Move tail forward to the node we just attached
            tail = tail->next;
        }

        // At most one list has remaining nodes — since it's already sorted,
        // just attach it directly instead of looping through it.
        tail->next = (list1 != nullptr) ? list1 : list2;

        // The actual merged list starts right after the dummy node.
        return dummy.next;
    }
};