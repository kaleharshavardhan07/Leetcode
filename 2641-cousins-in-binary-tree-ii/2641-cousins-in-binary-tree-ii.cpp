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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr)
            return result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> currentLevel;

            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node == nullptr) {
                    currentLevel.push_back(-1);
                } else {
                    currentLevel.push_back(node->val);

                    q.push(node->left);
                    q.push(node->right);
                }
            }
            result.push_back(currentLevel);
        }

        return result;
    }
    TreeNode* vectorToTree(const vector<vector<int>>& levels) {
        if (levels.empty() || levels[0].empty() || levels[0][0] == -1)
            return nullptr;

        TreeNode* root = new TreeNode(levels[0][0]);
        queue<TreeNode*> q;
        q.push(root);

        int levelIndex = 1;
        while (!q.empty() && levelIndex < levels.size()) {
            int levelSize = levels[levelIndex].size();
            for (int i = 0; i < levelSize; i += 2) {
                TreeNode* parent = q.front();
                q.pop();

                if (i < levelSize && levels[levelIndex][i] != -1) {
                    parent->left = new TreeNode(levels[levelIndex][i]);
                    q.push(parent->left);
                }

                if (i + 1 < levelSize && levels[levelIndex][i + 1] != -1) {
                    parent->right = new TreeNode(levels[levelIndex][i + 1]);
                    q.push(parent->right);
                }
            }
            levelIndex++;
        }

        return root;
    }
    TreeNode* replaceValueInTree(TreeNode* root) {

        vector<vector<int>> ret = levelOrder(root);

        for (int i = 0; i < ret.size(); i++) {

            int n = ret[i].size();

            if (n < 3) {
                for (int j = 0; j < n; j++)
                    ret[i][j] = 0;
            } else {
                int sum = 0;
                for (int j = 0; j < n; j++) {
                    if (ret[i][j] != -1) {
                        sum += ret[i][j];
                    }
                }

                int l = 0;
                while (l < n - 1) {

                    int temp = (ret[i][l] == -1 ? 0 : ret[i][l]) +
                               (ret[i][l + 1] == -1 ? 0 : ret[i][l + 1]);

                    int cot = sum - temp;
                    if (ret[i][l] != -1)
                        ret[i][l] = cot;
                    if (ret[i][l + 1] != -1)
                        ret[i][l + 1] = cot;
                    l = l + 2;
                }
            }
        }

        return vectorToTree(ret);
    }
};