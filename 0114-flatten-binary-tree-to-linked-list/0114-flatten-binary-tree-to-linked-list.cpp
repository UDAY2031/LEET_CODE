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
    void preorder(TreeNode* root, vector<int> &ans){
        if (!root) return;
        ans.push_back(root->val);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }

    TreeNode* buildList(const vector<int> &ans) {
        TreeNode* newRoot = new TreeNode(ans[0]);
        TreeNode* curr = newRoot;

        for (int i = 1; i < ans.size(); i++) {
            curr->right = new TreeNode(ans[i]);
            curr = curr->right;
        }
        return newRoot;
    }

    void flatten(TreeNode* root) {
        if (!root) return;

        vector<int> vals;
        preorder(root, vals);

        TreeNode* newRoot = buildList(vals);

        root->left = nullptr;
        root->right = newRoot->right;

        root->val = newRoot->val;
    }
};