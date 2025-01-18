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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if (!root)   return ans;
        queue<TreeNode*> Q;
        Q.push(root);

        while (!Q.empty())
        {
            int size = Q.size();
            int mx = INT_MIN;
            for (int i = 0; i < size; ++i)
            {
                if (Q.front()->left)  Q.push(Q.front()->left);
                if (Q.front()->right)  Q.push(Q.front()->right);

                mx = max(Q.front()->val, mx);
                Q.pop();
            }
            ans.push_back(mx);
        }
        return ans;

    }
};