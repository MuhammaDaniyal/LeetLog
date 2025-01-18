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
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        recursive("", sum, root);
        return sum;
    }

    void recursive(string str, int& sum, TreeNode* root)
    {
        if (!root)   return;
        str += to_string(root->val);

        if (!root->left && !root->right)
        {
            sum += stoi(str);
        }
        recursive(str, sum, root->left);
        recursive(str, sum, root->right);
    }
};