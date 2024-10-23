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
    ListNode* reverseList(ListNode* head) {
        vector<int>ret;
        ListNode * temp =head;
        while( temp){
            ret.push_back(temp->val);
            temp=temp->next;
        }
       
        temp=head;
         while( temp){
           int t=ret.back();
           ret.pop_back();
           temp->val=t;
            temp=temp->next;
        }
        return head;
    }
};