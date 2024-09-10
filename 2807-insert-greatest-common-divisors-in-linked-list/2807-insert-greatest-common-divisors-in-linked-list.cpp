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
    int solg(int m, int n) {
        int k = min(m, n);
        for (int i = k; i > 0; i--) {
            if (m % i == 0 && n % i == 0)
                return i;
        }
        return 1;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp = head;
        while (temp && temp->next) {

            int m = temp->val;
            int n = temp->next->val;
            int k=solg(m,n);
           ListNode* temp1 = new ListNode(k, temp->next);

            temp->next=temp1;

            temp=temp->next->next;
        }
        return head;
    }
};