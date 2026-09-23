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
    void reorderList(ListNode* head) {
        // Base case: Lists with 0, 1, or 2 nodes are already in the correct order.
        if (!head || !head->next || !head->next->next) {
            return;
        }

        // -------------------------------------------------------------
        // Step 1: Find the middle node using Slow & Fast pointers.
        // For an odd-length list: slow stops exactly at the middle node.
        // For an even-length list: slow stops at the end of the first half.
        // -------------------------------------------------------------
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;          // Move slow pointer 1 step forward
            fast = fast->next->next;    // Move fast pointer 2 steps forward
        }

        // -------------------------------------------------------------
        // Step 2: Split the list into two halves and reverse the second half.
        // -------------------------------------------------------------
        ListNode* second = slow->next;  // 'second' points to the start of the 2nd half
        slow->next = nullptr;           // Break the link to isolate the two lists

        ListNode* prev = nullptr;
        ListNode* curr = second;
        while (curr) {
            ListNode* nextTemp = curr->next; // Save the rest of the list
            curr->next = prev;               // Invert the current pointer
            prev = curr;                     // Move 'prev' forward
            curr = nextTemp;                 // Move 'curr' forward
        }
        second = prev; // 'prev' now points to the head of the reversed second half

        // -------------------------------------------------------------
        // Step 3: Interleave (merge) the first half and the reversed second half.
        // -------------------------------------------------------------
        ListNode* first = head;
        while (second) {
            // Cache the next nodes in both lists before updating connections
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;

            // Splice the current node of the second half after the current node of the first half
            first->next = second;
            second->next = tmp1;

            // Advance pointers to process the remaining elements
            first = tmp1;
            second = tmp2;
        }
    }
};