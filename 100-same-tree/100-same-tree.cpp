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
    void inorder(TreeNode* r1,TreeNode* r2,bool &same){
        if( !r1 && !r2) return;
        else if((r1 && !r2) || (!r1 && r2) ) {
            same=false;
            return;
        }
        if(same){
            if(r1->val!=r2->val) {
                same = false;
                return;
            }
            inorder(r1->left,r2->left,same); 
            inorder(r1->right,r2->right,same);
            
        }
        
                                      }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool f = true;
        inorder(p,q,f);
        return f;
    }
};