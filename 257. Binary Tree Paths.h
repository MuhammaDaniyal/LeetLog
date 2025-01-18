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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> vec;
        if (!root)   return vec;

        string str = "";
        bool b = 0;

        lessGoo(vec, str, root, b);
        return vec;
    }

    void lessGoo(vector<string>& vec, string str, TreeNode* root, bool b)
    {
        if (!root)  return;

        if (!b)           str = str + to_string(root->val);
        else            str = str + "->" + to_string(root->val);
        b = true;

        if (root->left)  lessGoo(vec, str, root->left, b);
        if (root->right)  lessGoo(vec, str, root->right, b);

        if (!root->left && !root->right)
            vec.push_back(str);
    }
};