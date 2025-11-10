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
    struct info {
        bool isBST;
        int minval;
        int maxval;
        int sum;
    };

    int maxSum = 0;

    info helper(TreeNode* root){
        if(!root) return {true, INT_MAX, INT_MIN, 0};

        info left = helper(root->left);
        info right = helper(root->right);

        info curr;

        if(left.isBST && right.isBST && root->val > left.maxval && root->val < right.minval){
            curr.isBST = true;
            curr.sum = root->val + left.sum + right.sum;
            curr.minval = min(root->val, left.minval);
            curr.maxval = max(root->val, right.maxval);

            maxSum = max(maxSum, curr.sum);
        }else{
            curr.isBST = false;
            curr.sum = 0;
            curr.minval = INT_MIN;
            curr.maxval = INT_MAX;
        }
        return curr;
    }
    int maxSumBST(TreeNode* root) {
        helper(root);
        return maxSum;
    }
};