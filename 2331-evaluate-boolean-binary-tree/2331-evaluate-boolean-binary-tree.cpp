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
    bool postorder(TreeNode* root){
        
        if(!root->left && !root->right) return root->val==0?false:true;
        bool a=false,b=false;
        if(root->left)  a = postorder(root->left);
        if(root->right) b = postorder(root->right);
        
        if(root->val==2) return a || b;
        //if(root->val==3) 
        return a && b;
        
    }
    
    bool evaluateTree(TreeNode* root) {
        return postorder(root);
    }
};