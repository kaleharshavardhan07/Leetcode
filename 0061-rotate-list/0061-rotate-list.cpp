class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || k == 0) {
            return head;
        }
        
        // Calculate the length of the list and find the last node
        int length = 1;
        ListNode *tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
            length++;
        }
        
        // Adjust k to avoid unnecessary rotations
        k = k % length;
        if (k == 0) {
            return head;
        }
        
        // Find the new tail (the node just before the new head)
        ListNode *new_tail = head;
        for (int i = 1; i < length - k; i++) {
            new_tail = new_tail->next;
        }
        
        // Update pointers to perform the rotation
        ListNode *new_head = new_tail->next;
        new_tail->next = nullptr;
        tail->next = head;
        
        return new_head;
    }
};

