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
    int tilt = 0;
public:
    int findTilt(TreeNode* root) {
        dfs(root);
        return tilt;
    }

    int dfs(TreeNode* root)
    {
        if (!root)  return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);

        int diff = abs(left - right);
        tilt += diff;
        return root->val + left + right;
    }
};