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
    //  void inorder(TreeNode* root, vector<int> &arr){

    //     if(root == nullptr){
    //         return;
    //     }

    //     inorder(root->left, arr);
    //     arr.push_back(root->val);
    //     inorder(root->right, arr);
    // }
    // vector<int> inorderTraversal(TreeNode* root) {
    //    vector<int> arr;
    //     inorder(root, arr);
    //     return arr;
    // }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;

        stack<TreeNode*> st;
        TreeNode* node = root;
        while (true) {
            if (node != NULL) {
                st.push(node);
                node = node->left;
            } else {
                if (st.empty())
                    break;
                else {
                    node = st.top();
                    st.pop();
                    ret.push_back(node->val);
                    node = node->right;
                }
            }
        }
        return ret;
    }
};
