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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* c = head;
        while (c != NULL) {
            c = c->next;
            count++;
        }
         if (count == n) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        ListNode* k = head;
        for (int i = 0; i < count - n - 1; i++) {
            k = k->next;
        }
        ListNode* t = k->next;

        if (t != NULL && t->next != NULL) {
            k->next = t->next;
        } else if (t != NULL) {
            k->next = NULL;
        }
        return head;
    }
};