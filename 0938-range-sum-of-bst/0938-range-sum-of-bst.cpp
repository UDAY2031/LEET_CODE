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
    void helper(TreeNode* root, vector<int>& res, int low, int high){
        if(root == NULL){
            return;
        }
        if(root->val > low) helper(root->left, res, low, high);
        if(root->val >= low && root->val <= high) res.push_back(root->val);
        if(root->val < high) helper(root->right, res, low, high);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int> res;
        helper(root, res, low, high);
        int sum = 0;
        for(int i = 0; i < res.size(); i++){
            sum += res[i];
        }
        return sum;
    }
};