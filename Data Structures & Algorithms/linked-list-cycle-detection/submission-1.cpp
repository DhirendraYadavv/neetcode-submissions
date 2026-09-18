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
    bool hasCycle(ListNode* head) {
        // Two pointers: slow moves 1 step at a time, fast moves 2 steps.
        // If there's a cycle, fast will eventually "lap" slow and they'll
        // meet inside the loop. If there's no cycle, fast reaches the end (nullptr).
        ListNode* slow = head;
        ListNode* fast = head;

        // We check "fast" and "fast->next" for null because fast moves
        // two steps each iteration — both need to be valid to move safely.
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;        // move slow by 1
            fast = fast->next->next;  // move fast by 2

            // If they ever point to the same node, there's a cycle.
            if (slow == fast) {
                return true;
            }
        }

        // fast hit the end of the list without ever meeting slow -> no cycle.
        return false;
    }
};
