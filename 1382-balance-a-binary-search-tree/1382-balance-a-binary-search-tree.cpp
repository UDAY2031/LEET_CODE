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
    TreeNode* helper(vector<int>& arr, int si, int ei){
        if(si > ei) return nullptr;

        int mid = si + (ei - si) / 2;

        TreeNode* curr = new TreeNode(arr[mid]);

        curr->left = helper(arr, si, mid - 1);
        curr->right = helper(arr, mid + 1, ei);

        return curr;
    }
    void inorder(TreeNode* root, vector<int>& arr){
        if(root == NULL) return;

        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        inorder(root,arr);

        int n = arr.size();
        return helper(arr, 0, n-1);
    }
};