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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long >ans;
        if(root==NULL && k>0)return -1;
        queue<TreeNode* >q;
        q.push(root);
        while( !q.empty()){
            int s= q.size();
            long long  sum=0;
            for( int i=0;i<s;i++){
               TreeNode *node=q.front();
                q.pop();
                if(node->left!=NULL)q.push(node->left);
                if(node->right!=NULL)q.push(node->right);
                sum+=node->val;
            }
            ans.push_back(sum);
        }
        sort(ans.begin(),ans.end(),greater<int>());
        if( ans.size()<k){
            return -1;
        }
        return ans[k-1];


    }
};