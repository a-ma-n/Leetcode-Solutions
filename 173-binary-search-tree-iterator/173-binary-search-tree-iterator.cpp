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
class BSTIterator {
public:
  /*  vector<int> io(TreeNode* r,vector<int> v){
        if(r==NULL)
            return v;
        io(r->left,v);
        //cout<<r->val;
        v.push_back(r->val);
        io(r->right,v);
        return v;
    }*/
    stack<TreeNode*> s;

    BSTIterator(TreeNode* root) {
         partialInorder(root);
    }
    
    void partialInorder(TreeNode* r){
        while(r!=NULL){
            s.push(r);
            r=r->left;            
        }
    }
    
    int next() {
       TreeNode* top=s.top();
        s.pop();
        partialInorder(top->right);
        return top->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */