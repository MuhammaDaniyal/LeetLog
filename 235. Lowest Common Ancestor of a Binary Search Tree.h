/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    TreeNode* recursion(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        // p < q
        if (root->val >= p->val)
        {
            if (root->val <= q->val)
                return root;
            return recursion(root->left, p, q);
        }
        return recursion(root->right, p, q);

    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)   return nullptr;

        // p->val will always be smaller than q
        if (p->val > q->val)
            swap(p, q);

        return recursion(root, p, q);
    }
};