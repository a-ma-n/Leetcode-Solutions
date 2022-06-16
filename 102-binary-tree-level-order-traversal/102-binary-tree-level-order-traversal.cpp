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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue <pair<TreeNode*,int>> q;
        
       // vector<int> res;
        map<int,vector<int>> mpp;
        vector<vector<int>> ans;
        if(root == NULL) 
            return ans;
        
        q.push({root,0});
        
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int level = q.front().second;
            cout<<level;
            q.pop();
            
            if(node->left!=NULL)
                 q.push({node->left,level+1});
             if(node->right!=NULL)
                 q.push({node->right,level+1});
            mpp[level].push_back(node->val);
        }
        
        for(auto it:mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};