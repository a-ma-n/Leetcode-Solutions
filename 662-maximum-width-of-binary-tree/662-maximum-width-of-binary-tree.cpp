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
    int c=0;
    int widthOfBinaryTree(TreeNode* root) {
    if(!root)
        return 0;
    int ans=0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            int size = q.size();
            int mmin = q.front().second;
            int first,last;
            for(int i=0;i<size;i++){
                // long due to last test case
                long cur_id = q.front().second-mmin;
                TreeNode* node = q.front().first;
                q.pop();
                if(i==0)
                    first = cur_id;
                if(i==size-1)
                    last = cur_id;
                if(node->left)
                    q.push({node->left,cur_id*2+1});
                if(node->right)
                    q.push({node->right,cur_id*2+2});
            }
            ans = max(ans,last-first+1);
        }
        return ans;

    }
};



// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */

// class Solution {
// public:
//     int c=0;
//     int widthOfBinaryTree(TreeNode* root) {
        
//         TreeNode * head=root;
        
//         //cout<<root->val;
//         if(root==NULL){
//             return 0;
//         }
//         if(root == head && c==0){
//             c++;
//             int a=widthOfBinaryTree(root->left);
//             int b=widthOfBinaryTree(root->right);
//             cout<<"a:"<<a<<endl;
//             cout<<"b:"<<b<<endl;
//             int c=a+b;
//             cout<<"\nc:"<<c<<endl;
//             return c;
            
//         }
//         else if(root->left == NULL && root->right ==NULL){
//            // cout<<root->val;
//             return 1;
//         }
//         else{
//             //cout<<"left width:"<<widthOfBinaryTree(root->left)<<endl;
//            // cout<<"right width:"<<widthOfBinaryTree(root->right)<<endl;
//             //cout<<root->val;
//             int k=1+max(widthOfBinaryTree(root->left),widthOfBinaryTree(root->right));
            
//             cout<<"\nk: "<<k<<endl;
//             return k;
//         }
        
//     }
// };



       
//         TreeNode * head=root;
        
//         //cout<<root->val;
//         if(root==NULL){
//             return 0;
//         }
//         if(root == head && c==0){
//             c++;
//             int a=widthOfBinaryTree(root->left);
//             int b=widthOfBinaryTree(root->right);
//             cout<<"a:"<<a<<endl;
//             cout<<"b:"<<b<<endl;
//             int c=a+b;
//             cout<<"\nc:"<<c<<endl;
//             return c;
            
//         }
//         else if(root->left == NULL && root->right ==NULL){
//            // cout<<root->val;
//             return 1;
//         }
//         else{
//             //cout<<"left width:"<<widthOfBinaryTree(root->left)<<endl;
//            // cout<<"right width:"<<widthOfBinaryTree(root->right)<<endl;
//             //cout<<root->val;
//             int k=1+max(widthOfBinaryTree(root->left),widthOfBinaryTree(root->right));
            
//             cout<<"\nk: "<<k<<endl;
//             return k;
//         }