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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return root;
        }

        if(root == p || root == q){
            return root;
        }

        TreeNode* isLeft = lowestCommonAncestor(root->left, p, q);
        TreeNode* isRight = lowestCommonAncestor(root->right, p, q);
        
        if(isLeft != NULL && isRight != NULL){
            return root;
        }
        return (isLeft != NULL) ? isLeft : isRight;
    }
};