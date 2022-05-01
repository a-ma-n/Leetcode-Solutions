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
    int rtl=0;
    void preorder(TreeNode* r,int cn){
        if(r!=NULL)
        {
            // 1->0->0 will give 100
            // 1->0->1 will give 101
            // 1->1->1 will give 111
            // 1->1->0 will give 110
            cn = cn<<1 | r->val;
            if(r->left ==NULL && r->right==NULL)
                rtl+=cn;
            preorder(r->left,cn);
            preorder(r->right,cn);
        }
    }
    
    int sumRootToLeaf(TreeNode* root) {
        preorder(root,0);
        return rtl;
    }
};