class Solution {
public:
    int DR[4]={0,0,1,-1};
    int DC[4]={1,-1,0,0};
    void dfs(int i,int j,vector<vector<int>>& grid,int &count,bool removal){
        int row=grid.size();
        int col=grid[0].size();
        if( i<0 || j<0 || i>row-1 || j>col-1 || grid[i][j]!=1) return;
        // mark visited nodes with -1
        grid[i][j]=0;
        dfs(i+1,j,grid,count,removal);
        dfs(i-1,j,grid,count,removal);
        dfs(i,j+1,grid,count,removal);
        dfs(i,j-1,grid,count,removal);
        if(removal) count++; 
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int row = grid.size(),col = grid[0].size(),count=0; 
        for(int i =0;i<row;i++)
            for(int j=0;j<col;j++)
                if((i==0 || j==0 || i==row-1 || j==col-1) && grid[i][j]==1)
                dfs(i,j,grid,count,false);
         for(int i =0;i<row;i++)
            for(int j=0;j<col;j++)
                if(grid[i][j]==1){
                    dfs(i,j,grid,count,true);
                    // count++;
                }
        return count;
    }
};