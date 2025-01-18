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

    int minNum = INT_MAX;
    TreeNode* prev = nullptr;

    int getMinimumDifference(TreeNode* root) {
        getMin(root);
        return minNum;
    }

    void getMin(TreeNode* root)
    {
        if (root->left)  getMin(root->left);
        if (prev)    minNum = min(minNum, abs(root->val - prev->val));
        prev = root;
        if (root->right) getMin(root->right);
    }
};