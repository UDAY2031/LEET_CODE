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
    TreeNode* helper(TreeNode* curr,int val){

        if(curr == NULL){
            curr = new TreeNode(val);
            return curr;
        }

        curr->right = helper(curr->right,val);
        return curr;
    }
    void inorder(TreeNode* root, vector<int>& arr){
        if(root == NULL) return;

        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> arr;
        inorder(root, arr);
        int n = arr.size();

        TreeNode* curr = NULL;
        for(int i = 0; i < n; i++){
            curr = helper(curr, arr[i]);
        }
        return curr;
    }
};