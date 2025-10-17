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
    TreeNode* Inorder(TreeNode* root){
        while(root->left != NULL){
            root = root->left;
        }
        return root;
    }
    TreeNode* helper(TreeNode* root, int key){
        if(root == NULL){
            return NULL;
        }

        if(key < root->val){
            root->left =  helper(root->left, key);
        }else if(key > root->val){
            root->right = helper(root->right, key);
        }else{
            if(root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }else if(root->left != NULL && root->right == NULL){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }else if(root->left == NULL && root->right != NULL){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }else if(root->left != NULL && root->right != NULL){
                TreeNode* rightLeft = Inorder(root->right);
                root->val = rightLeft->val;
                root->right = helper(root->right, rightLeft->val);
            }
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        return helper(root, key);
    }
};