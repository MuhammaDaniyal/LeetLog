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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums, 0, nums.size());
    }

    TreeNode* dfs(vector<int>& nums, int start, int end)
    {
        if (start >= end)    return nullptr;

        int midd = (start + end) / 2;
        TreeNode* root = new TreeNode(nums[midd]);

        root->left = dfs(nums, start, midd);
        root->right = dfs(nums, midd + 1, end);
        return root;
    }
};