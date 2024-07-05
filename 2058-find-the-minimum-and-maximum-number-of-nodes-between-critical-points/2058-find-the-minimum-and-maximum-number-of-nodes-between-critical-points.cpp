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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> index;

        if (!head || !head->next || !head->next->next)
            return {-1, -1};

        ListNode* prev = head;
        ListNode* curr = prev->next;
        ListNode* net = curr->next;
        int node = 2;
        while (net) {
            if ((prev->val < curr->val && curr->val > net->val) ||
                (prev->val > curr->val && curr->val < net->val)) {
                index.push_back(node);
            }
            prev = curr;
            curr = net;
            net = net->next;
            node++;
        }
        sort(index.begin(), index.end());
        if (index.size() < 2) {
            return {-1, -1};
        }
        int min=INT_MAX;
        for(int i=0;i<index.size()-1;i++){
            if( min>(index[i+1]-index[i])){
                min=index[i+1]-index[i];
            }
        }
        int diff2 = index[index.size() - 1] - index[0];
        return {min, diff2};
    }
};