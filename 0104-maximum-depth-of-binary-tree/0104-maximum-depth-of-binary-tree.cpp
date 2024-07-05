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
       if (root == nullptr) {
            return 0;
        }
        int leftDepth = trav(root->left);
        int rightDepth = trav(root->right);
        return 1 + max(leftDepth, rightDepth);
    }
    int maxDepth(TreeNode* root) {
        int count = trav(root);
        return count;
    }
};