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
    vector<int> res;
    void dfs(Node* root){
        if(root==NULL) return;
        for(auto it:root->children){
            dfs(it);
        }
        res.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        dfs(root);
        return res;
    }
};