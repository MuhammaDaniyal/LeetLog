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
    int minDepth(TreeNode* root) {
        if (!root)   return 0;

        int left = root->left ? minDepth(root->left) : -1;
        int right = root->right ? minDepth(root->right) : -1;

        if (left == -1 && right == -1)   return 1;
        else if (left == -1 && right != -1)   return right + 1;
        else if (left != -1 && right == -1)   return left + 1;

        return min(left, right) + 1;

    }

};