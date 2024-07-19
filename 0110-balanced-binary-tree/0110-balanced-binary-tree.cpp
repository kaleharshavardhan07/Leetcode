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
 #include <algorithm> 
 #include<iostream>
class Solution {
public:
    
    int height(TreeNode* root, int* indi) {
        if (root == NULL) {
            return 0;
        }
        int lh = height(root->left,indi);
        int rh = height(root->right, indi);
        if (abs(lh - rh) > 1) {
            *indi = -1;
        }
        int k;
        if(lh>=rh){
            k=lh;
        }
        else{k=rh;}
        return 1 + k;
    }
    bool isBalanced(TreeNode* root) {
        int indi = 0;
        int k = height(root, &indi);
        if (indi == -1) {
            return false;
        }
        return true;
    }
};