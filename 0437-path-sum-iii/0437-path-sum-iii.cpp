// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//  void solve( TreeNode* root, int target,int add, int &count){
//     if( root==NULL){
//         return ;
//     }
//     else{
//         if( target==root->val+add){
//             count++;
//         }
//         int temp=root->val;
//         solve(root->left,target,add+temp,count);
//         solve(root->right,target,add+temp,count);
//         solve(root->left,target,0,count);
//         solve(root->right,target,0,count);
//     }
//  }
//     int pathSum(TreeNode* root, int targetSum) {
//         int count=0;
//         solve(root,targetSum,0,count);
//         return count;
//     }
// };

class Solution {
public:
    void solve(TreeNode* root, int targetSum, long long currentSum, int& count) {
        if (root == nullptr) {
            return;
        }

        currentSum += root->val;

        if (currentSum == targetSum) {
            count++;
        }

        solve(root->left, targetSum, currentSum, count);
        solve(root->right, targetSum, currentSum, count);
    }

    void dfs(TreeNode* root, int targetSum, int& count) {
        if (root == nullptr) {
            return;
        }

        solve(root, targetSum, 0, count);

        dfs(root->left, targetSum, count);
        dfs(root->right, targetSum, count);
    }

    int pathSum(TreeNode* root, int targetSum) {
        int count = 0;

        dfs(root, targetSum, count);

        return count;
    }
};
