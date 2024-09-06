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
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to delete nodes from the linked list that are present in the set
    ListNode* deleteNodes(ListNode* head, const unordered_set<int>& nums_set) {
        // Create a dummy node to handle edge cases such as removing the head
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* current = head;

        // Traverse the linked list
        while (current) {
            if (nums_set.find(current->val) != nums_set.end()) {
                // If the current node's value is in nums, skip it
                prev->next = current->next;
            } else {
                // Otherwise, move the prev pointer
                prev = current;
            }
            current = current->next;
        }

        // Return the modified list, starting from dummy->next
        return dummy->next;
    }

    // Function to modify the linked list based on nums vector
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        // Convert nums to an unordered_set for fast lookup
        unordered_set<int> nums_set(nums.begin(), nums.end());

        // Call deleteNodes function to remove nodes from the linked list
        return deleteNodes(head, nums_set);
    }
};
