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
    bool hasPathSum(TreeNode* root, int targetSum) {
        return recursive(root, targetSum, 0);
    }

    bool recursive(TreeNode* root, int target, int present)
    {
        if (!root) return false;
        present += root->val;
        if (present == target && (root->left == nullptr && root->right == nullptr))
            return true;

        bool left = recursive(root->left, target, present);
        bool right = recursive(root->right, target, present);
        return left || right;
    }
};