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
    bool helper(TreeNode* root, int targetSum, int currSum) {
        if (root == nullptr) return false;

        currSum += root->val;


        if (root->left == nullptr && root->right == nullptr) {
            return currSum == targetSum;
        }

        return helper(root->left, targetSum, currSum) ||
               helper(root->right, targetSum, currSum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return helper(root, targetSum, 0);
    }
};