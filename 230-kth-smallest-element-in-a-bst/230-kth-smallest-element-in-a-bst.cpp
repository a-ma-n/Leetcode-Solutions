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
    int val=0,ans=0;
    void io(TreeNode* r){
        if(r==NULL)
            return ;
        io(r->left);
        val--;
        if(val==0)
            ans=r->val;
        io(r->right);
       
    }
    int kthSmallest(TreeNode* root, int k) {
        val=k;
        io(root);
        return ans;
    }
};