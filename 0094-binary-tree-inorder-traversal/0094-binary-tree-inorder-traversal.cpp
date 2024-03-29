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
    // DONE WITH MORRIS TRAVERSAL
    // TC: O(N)
    // SC: O(1)
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode *cur=root;
        
        // 1- done with inorder traversal
        
        while(cur!=NULL){
            
            // doesnt have a left -> go right, stores the root value here.
            if(cur->left == NULL){
                inorder.push_back(cur->val);
                cur = cur->right;
            }
            
            else{
                // go to the last guy of the left subtree
                
                TreeNode *prev = cur->left;
                // If there exists a right and it is not pointing to itself then
                while(prev->right && prev->right !=cur){
                    prev= prev->right; 
                }

                // we make a thread point back to the cur, move cur to left
                if(prev ->right ==NULL){
                    // For preorder 
                    /*
                    prev->right = cur;
                    preorder.push_back(cur->val);
                    cur=cur->left;
                    */
                    prev->right = cur;
                    cur=cur->left;
                }
                else{
                    // if thread exists from another bottomost node to this node
                    //remove the link we added
                    prev->right =NULL;

                    inorder.push_back(cur->val);
                    cur = cur->right;
                    // For preorder 
                    /*
                    prev->right =NULL;
                    cur = cur->right;
                    */
                }
                
            }
        }
        return inorder;
    }
};