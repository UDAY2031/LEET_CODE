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
    bool isIdentity(TreeNode* root, TreeNode* subRoot){
        if(root == NULL && subRoot == NULL){
            return true;
        }else if(root == NULL || subRoot == NULL){
            return false;
        }
        if(root->val != subRoot->val){
            return false;
        }

        return isIdentity(root->left, subRoot->left) && isIdentity(root->right, subRoot->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL && subRoot == NULL){
            return true;
        }else if(root == NULL || subRoot == NULL){
            return false;
        }
        if(root->val == subRoot->val){
            if(isIdentity(root, subRoot)){
                return true;
            }
        }
        int isLeftSubTree = isSubtree(root->left, subRoot);
        if(!isLeftSubTree){
            return isSubtree(root->right, subRoot);
        }
        return true;
    }
};