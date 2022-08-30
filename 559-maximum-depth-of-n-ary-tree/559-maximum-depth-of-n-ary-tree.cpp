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
    int mx=INT_MIN;
    void dfs(Node* root,int h){
        mx=max(mx,h);
        for(auto it:root->children){
            dfs(it,h+1);
        }
    }
    int maxDepth(Node* root) {
        if(root == NULL) return 0;
        int h=1;
        dfs(root,h);
        return mx;
    }
};