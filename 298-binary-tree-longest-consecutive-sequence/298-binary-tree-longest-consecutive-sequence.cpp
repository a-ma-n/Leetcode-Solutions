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
    void getans(TreeNode* root,int &max_val,int len){
        if(!root) return;
        max_val=max(max_val,len);
        if(root->left && root->left->val == root->val+1)
            getans(root->left,max_val,len+1);
        else
            getans(root->left,max_val,1);
        if(root->right && root->right->val == root->val+1)
            getans(root->right,max_val,len+1);
        else
            getans(root->right,max_val,1);
    }
    int longestConsecutive(TreeNode* root) {
        int max_val=0;
        getans(root,max_val,1);
        return max_val;
    }
};