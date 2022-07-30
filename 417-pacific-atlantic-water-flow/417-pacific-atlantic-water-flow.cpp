class Solution {
public:
    // We need to find the cells connected to Pacific Ocean & Atlantic Ocean
    // We then need to find the intersection of these cells
    
    //     Time Complexity : O(M*N), in worst case, all cells are reachable to both oceans and would be visited twice. This case can occur when all elements are equal.
    // Space Complexity : O(M*N),to mark the atlantic and pacific visited cells.

    int m,n;
    vector<vector<bool>> atlantic,pacific;
    vector<vector<int>> ans;
    // denotes cells reachable starting from atlantic and pacific edged cells respectively
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& mat) {
         if(!size(mat)) return ans;
        m = size(mat),n=size(mat[0]);
        atlantic = pacific = vector<vector<bool>>(m,vector<bool>(n,false));
        // perform dfs from all edge cells (ocean-connected cells)
        for( int i = 0 ; i< m ; i++) dfs(mat,pacific,i,0),dfs(mat,atlantic,i,n-1);
        for( int i = 0 ; i< n ; i++) dfs(mat,pacific,0,i),dfs(mat,atlantic,m-1,i);
        return ans;
    }
    void dfs(vector<vector<int>>& mat, vector<vector<bool>>& vis,int i, int j){
        if(vis[i][j]) return;
        vis[i][j]=true;
        // if cell reachable from both the oceans, insert the ans into the final ans vector
        if(atlantic[i][j] && pacific[i][j] ) ans.push_back(vector<int>{i,j});
        // dfs from current cell only if next cell is greater           
        if(i+1<m && mat[i+1][j]>=mat[i][j] ) dfs(mat,vis,i+1,j);  // up
        if(i-1>=0 && mat[i-1][j]>=mat[i][j] ) dfs(mat,vis,i-1,j);  // down
        if(j+1<n && mat[i][j+1]>=mat[i][j] ) dfs(mat,vis,i,j+1);  // right
        if(j-1>=0 && mat[i][j-1]>=mat[i][j] ) dfs(mat,vis,i,j-1);  // left
    }
};