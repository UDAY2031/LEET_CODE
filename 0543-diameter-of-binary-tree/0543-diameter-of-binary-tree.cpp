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
    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int l = height(root->left);
        int r = height(root->right);

        int res = max(l, r) + 1;
        return res;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }

        int currDiam = height(root->left) + height(root->right);

        int leftDiam = diameterOfBinaryTree(root->left);

        int rightDiam = diameterOfBinaryTree(root->right);

        int res = max(currDiam, max(leftDiam, rightDiam));
        return res;
    }
};