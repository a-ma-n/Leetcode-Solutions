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
    int sum=0,deepest=0;
    //vector <int> v{0,1000};
    int deepestLeavesSum(TreeNode* r,int depth = 0){
        if(r==NULL)
            return 0;
        if(r->left ==NULL && r->right ==NULL)
        {
           if(depth ==deepest){
               sum+=r->val;
           }
           if(depth>deepest){
               sum=r->val;
               deepest = depth;
           }
        }

        deepestLeavesSum(r->right,depth+1);
        deepestLeavesSum(r->left,depth+1);
        return sum;
    }
    
};