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
    bool isValidBST(TreeNode* root) {
        if (!root || (!root->left && !root->right))   return true;
        long int prev = LONG_MIN;
        return recursive(root, prev);
    }

    bool recursive(TreeNode* root, long int& prev)
    {
        if (!root)   return true;

        bool left = recursive(root->left, prev);
        if (root->val <= prev)
            return false;
        prev = root->val;

        if (left == false)   return false;
        bool right = recursive(root->right, prev);
        `
            return left && right;
    }

};