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
    vector<int> solve(TreeNode* root) {
        vector<int> ret;
        if(root==NULL)return ret;
        queue<TreeNode * >st;
        st.push(root);
        while( !st.empty()){
            int size = st.size();
            int maxi = INT_MIN;
            for (int i = 0; i < size; i++) {
                TreeNode* current = st.front();
                st.pop();
                maxi = max(maxi, current->val);
                if (current->left)
                    st.push(current->left);
                if (current->right)
                    st.push(current->right);
            }
            ret.push_back(maxi);

            
        }
        return ret;
    }
    vector<int> largestValues(TreeNode* root) {
        return solve( root);
    }
};