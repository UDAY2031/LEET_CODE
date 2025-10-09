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
    bool LCA(TreeNode* root, TreeNode* n, vector<TreeNode*>& path){
        if(root == NULL){
            return false;
        }
        path.push_back(root);
        if(root == n){
            return true;
        }
        int isleft = LCA(root->left,n,path);
        int isright = LCA(root->right,n,path);

        if(isleft || isright){
            return true;
        }
        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1;
        vector<TreeNode*> path2;

        LCA(root, p, path1);
        LCA(root, q, path2);

        TreeNode* lca = nullptr;

        for(int i = 0, j = 0; i < path1.size() && j < path2.size(); i++, j++){
            if(path1[i] != path2[j]){
                break;
                return lca;
            }
            lca = path1[i];
        }
        return lca;
    }
};