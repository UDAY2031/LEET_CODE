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
    bool helper(TreeNode* root, TreeNode* n, vector<TreeNode*> & path){
        if(root == NULL){
            return false;
        }

        path.push_back(root);
        if(root == n){
            return true;
        }
        int isleft = helper(root->left, n, path);
        int isright = helper(root->right, n, path);

        if(isleft || isright){
            return true;
        }

        path.pop_back();
        return false;
    }
    TreeNode* LCA(TreeNode* root, TreeNode* n1, TreeNode* n2){
        vector<TreeNode*> path1;
        vector<TreeNode*> path2;

        helper(root, n1, path1);
        helper(root, n2, path2);

        TreeNode* lca = nullptr;

        for(int i = 0; i < path1.size() && i < path2.size(); i++){
            if(path1[i] != path2[i]){
                break;
                return lca;
            }
            lca = path1[i];
        }
        return lca;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return LCA(root, p,q);
    }
};