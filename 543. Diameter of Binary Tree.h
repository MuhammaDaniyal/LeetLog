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
    int maxheight(TreeNode* root, int& mx) {
        if (root == NULL) return 0;
        int p = maxheight(root->left, mx);
        int q = maxheight(root->right, mx);
        mx = max(mx, p + q);
        return 1 + max(p, q);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int mx = INT_MIN;
        maxheight(root, mx);
        return mx;
    }
};