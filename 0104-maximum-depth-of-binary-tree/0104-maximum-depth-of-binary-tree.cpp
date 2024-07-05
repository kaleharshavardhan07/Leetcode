/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int trav(TreeNode* root) {
        if (root) {

            return max(1 + trav(root->right), 1 + trav(root->right));
        }
        return 0;
    }
    int maxDepth(TreeNode* root) {
        int count = trav(root);
        return count;
    }
};