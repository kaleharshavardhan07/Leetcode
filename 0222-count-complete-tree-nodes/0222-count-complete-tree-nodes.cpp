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
    int countNodes(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int l,r;
        if (root->left != NULL) {
            l = countNodes(root->left);
        } else {
            l = 0;
        }
        if (root->right != NULL) {
             r = countNodes(root->right);
        } else {
        r = 0;
        }

        return 1 + l + r;
    }
};