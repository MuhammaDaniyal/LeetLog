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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root)   return {};
        vector<vector<int>> Ans;

        queue<TreeNode*> Q;
        Q.push(root);
        int level = 0;
        int size;
        TreeNode* temp;
        while (!Q.empty())
        {
            vector<int> concat;
            size = Q.size();
            for (int i = 0; i < size; ++i)
            {
                temp = Q.front();
                Q.pop();
                concat.push_back(temp->val);
                if (temp->right)   Q.push(temp->right);
                if (temp->left)   Q.push(temp->left);
            }
            if (level % 2 == 0)
                reverse(concat.begin(), concat.end());

            Ans.push_back(concat);
            level++;
        }

        return Ans;
    }
};