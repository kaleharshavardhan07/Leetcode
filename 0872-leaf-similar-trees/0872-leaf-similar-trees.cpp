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
    void solve(TreeNode* root, vector<int>& ret) {
        if (root == NULL) {
            return ;
        }
        if (root->left == NULL && root->right == NULL) {
            ret.push_back(root->val);
        }
        solve(root->left, ret);
        solve(root->right, ret);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> ret1;
        vector<int> ret2;
        solve(root1, ret1);
        solve(root2, ret2);
        if (ret1.size() != ret2.size())
            return false;
        for (int i = 0; i < ret1.size(); i++) {
            if (ret1[i] != ret2[i])
                return false;
        }
        return true;
    }
};