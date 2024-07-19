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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         if (!root) return {};
        queue<TreeNode*> st;
        vector < vector<int>> ret;
        st.push(root);
        int flag = 0;
        while (!st.empty()) {
            vector<int> vec;
            flag++;
            int size = st.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = st.front();
                st.pop();
                vec.push_back(node->val);
                if (node->left != NULL)
                    st.push(node->left);
                if (node->right != NULL)
                    st.push(node->right);
            }
            if (flag % 2 != 0)
                ret.push_back(vec);
            else {
                reverse(vec.begin(), vec.end());
                ret.push_back(vec);
            }
        }
        return ret;
    }
};