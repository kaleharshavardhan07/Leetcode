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
    ListNode* deleteMiddle(ListNode* head) {
         if (!head || !head->next) return nullptr;

        // Use two pointers, slow and fast
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;  // To keep track of the node before the middle

        // Move fast pointer by 2 steps and slow pointer by 1 step
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Slow is now at the middle node, and prev is before it
        prev->next = slow->next;  // Remove the middle node

        return head;
    }
};