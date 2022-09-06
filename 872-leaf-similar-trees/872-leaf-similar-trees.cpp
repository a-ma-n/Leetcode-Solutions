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
   
    void getsequence(TreeNode* root,vector<int> &s){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL)
            s.push_back(root->val);
        getsequence(root->left,s);
        getsequence(root->right,s);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> s1,s2;
        getsequence(root1,s1);
        getsequence(root2,s2);
        if(s1==s2) return true;
        return false;
    }
};