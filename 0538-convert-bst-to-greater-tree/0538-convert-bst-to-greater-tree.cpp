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
    void BST(TreeNode* root, vector<int>& nums, int& idx){
        if(!root) return;

        BST(root->left, nums, idx);
        root->val = nums[idx++];
        BST(root->right, nums, idx);
    }
    vector<int> helper(vector<int>& arr, vector<int>& nums){
        int n = arr.size();
        int sum = 0;

        for(int i = n-1; i >= 0; i--){
            sum += arr[i];
            nums.push_back(sum);
        }
        reverse(nums.begin(), nums.end());
        return nums;
    }
    void inorder(TreeNode* root, vector<int>& arr){
        if(root == NULL) return;

        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }
    TreeNode* convertBST(TreeNode* root) {
        vector<int> arr;
        inorder(root, arr);
        vector<int> nums;
        helper(arr, nums);
        int idx = 0;
        BST(root, nums, idx);
        return root;
    }
};