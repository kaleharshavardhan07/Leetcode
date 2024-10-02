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
    void solve(TreeNode* root, vector<string>& ret, string path) {

          if (root == nullptr) return;
        
        if (!path.empty()) path += "->";
        path += to_string(root->val);
        
        if (root->left == nullptr && root->right == nullptr) {
            ret.push_back(path);
            return;
        }
        
        solve(root->left, ret, path);
        solve(root->right, ret, path);
    }
    vector<string> binaryTreePaths(TreeNode* root) {

        vector<string> ret;
        if (root == NULL)
            return {};
        solve(root, ret, "");
        return ret;
    }
};