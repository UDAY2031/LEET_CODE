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
    string duplicate(TreeNode* root, unordered_map<string, int> &mp, vector<TreeNode*> &v){
        if(root == NULL){
            return "";
        }

        string a = duplicate(root->left, mp, v);
        string b = duplicate(root->right, mp, v);
        string temp = to_string(root->val)+ "," + a + "," + b;
        mp[temp]++;
        if(mp[temp] == 2){
            v.push_back(root);
        }
        return temp;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> mp;
        vector<TreeNode*> v;
        duplicate(root, mp, v);
        return v;
    }
};