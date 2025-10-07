/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelorder(Node* root){
        vector<vector<int>> ans;
        queue<Node*> q;
        if(root == NULL){
            return ans;
        }
        q.push(root);

        while(!q.empty()){
            vector<int> level;
            int size = q.size();

            for(int i = 0; i < size; i++){
                Node* curr = q.front();
                q.pop();

                level.push_back(curr->val);

                for(auto child : curr->children){
                    q.push(child);
                }

            }
            ans.push_back(level);
        }
        return ans;
    }
    vector<vector<int>> levelOrder(Node* root) {
        return levelorder(root);
    }
};