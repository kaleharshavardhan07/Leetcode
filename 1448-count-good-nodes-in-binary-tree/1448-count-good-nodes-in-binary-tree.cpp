/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve ( TreeNode* root , int &count, int  max){
        if( root==NULL){
            return;
        }
        if( root->val>=max){
            max=root->val;
            count++;


        }
        if( root->left)solve(root->left,count,max);
        if( root->right)solve(root->right,count,max);


    }
    int goodNodes(TreeNode* root) {
        int count=0;
        solve(root,count,INT_MIN);
        return count;

         

    }
};