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
    int maxLevelSum(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL){
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            vector<int> level;

            for(int i = 0; i < n; i++){
                TreeNode* curr = q.front();
                q.pop();

                level.push_back(curr->val);

                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
            res.push_back(level);
        }
        int mini = res[0][0];
        int a = 0;
        for(int i = 1; i < res.size(); i++){
            int ans = 0;
            for(int j = 0; j < res[i].size(); j++){
                ans += res[i][j];
            }
            if(ans > mini){
                mini = ans;
                a = i;
            }
        }
        return a + 1;
    }
};