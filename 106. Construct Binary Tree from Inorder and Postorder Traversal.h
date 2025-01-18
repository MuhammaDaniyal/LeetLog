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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() != postorder.size()) return nullptr;
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); ++i)
            mp[inorder[i]] = i;

        return dfs(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, mp);
    }

    TreeNode* dfs(vector<int>& inOrder, int inS, int inE, vector<int>& postOrder, int pS, int pE, unordered_map<int, int>& mp) {

        if (inS > inE || pS > pE) return nullptr;

        int rootVal = postOrder[pE];
        TreeNode* root = new TreeNode(rootVal);

        int mid = mp[rootVal];
        int leftSize = mid - inS;

        root->left = dfs(inOrder, inS, mid - 1, postOrder, pS, pS + leftSize - 1, mp);
        root->right = dfs(inOrder, mid + 1, inE, postOrder, pS + leftSize, pE - 1, mp);

        return root;
    }
};