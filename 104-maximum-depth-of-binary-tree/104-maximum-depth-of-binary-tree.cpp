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
    void findHeight(TreeNode* root,int level,int &maxHeight){
        if(root == NULL) return;
        if(maxHeight<level) maxHeight = level; 
        findHeight(root->left,level+1,maxHeight);
        findHeight(root->right,level+1,maxHeight);
        return;
    }
    
    
    int maxDepth(TreeNode* root) {
        if (root==NULL )
            return 0;
        int maxHeight=0;
        findHeight(root,1,maxHeight);
        return maxHeight;
    }
};