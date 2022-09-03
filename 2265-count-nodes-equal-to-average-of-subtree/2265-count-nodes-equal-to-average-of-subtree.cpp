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
    int count=0;
    unordered_map<TreeNode*,int>mp; 
    
    int countNode(TreeNode* root){
        if(root==0) return 0;
        if(mp.find(root)!=mp.end()) return mp[root];
        return mp[root]=1+countNode(root->left)+countNode(root->right);
    }
    int helper(TreeNode* root){
        if(root==NULL) return 0;
        int l = helper(root->left);
        int countL = countNode(root->left);
        int r = helper(root->right);
        int countR = countNode(root->right);
        
        int total = countL+countR+1;
        int avg = (l+r+root->val)/total;
        
        if(avg==root->val)
            count+=1;
        return l+r+root->val;
    }
  
    int averageOfSubtree(TreeNode* root) {
        helper(root);
        return count;
       // return answer;
    }
};