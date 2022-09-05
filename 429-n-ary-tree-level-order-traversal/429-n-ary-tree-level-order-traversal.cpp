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
//bfs
// layer 6,7,8,9,10 => we need to keep track of the level and then add accordingly to the queue
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root== NULL) return {};
        
        queue<Node*> q;
        vector<vector<int>> res;
        q.push(root);
        //q.push(NULL);
        int level;
        
        while(!q.empty()){
            int size = q.size();
            vector<int> currlevel;
            for(int i =0;i<size;i++){
                Node* temp = q.front();
                q.pop();
                currlevel.push_back(temp->val);
                for(auto n:temp->children)
                    q.push(n);
            }
            res.push_back(currlevel);         
        }
        return res;
    }
};