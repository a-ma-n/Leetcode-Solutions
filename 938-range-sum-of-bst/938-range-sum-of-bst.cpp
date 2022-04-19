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
    int sum=0;
    int io(TreeNode* r,int l,int h){
        if(r){
        io(r->left,l,h);
        if(r->val >= l && r->val <= h){
            sum+=r->val;
        }
        io(r->right,l,h);
        }
        return sum;
    }
    
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        return io(root,low,high);
    }
};