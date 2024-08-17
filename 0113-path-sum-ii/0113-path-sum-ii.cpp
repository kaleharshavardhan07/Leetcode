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
    void solve(TreeNode* root, int targetSum, vector<vector<int>>& ret,
               vector<int> reti) {
        if (root == NULL)
            return;
        reti.push_back(root->val);
        targetSum -= root->val;
        if (root->left == NULL && root->right == NULL && targetSum == 0) {
            ret.push_back(reti);
        }

        solve(root->left, targetSum, ret, reti);
        solve(root->right, targetSum, ret, reti);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> reti;
        vector<vector<int>> ret;
        solve(root, targetSum, ret, reti);
        return ret;
    }
};