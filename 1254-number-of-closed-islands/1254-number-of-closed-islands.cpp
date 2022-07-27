class Solution {
public:
    int DR[4]={0,0,1,-1};
    int DC[4]={1,-1,0,0};
    // check for a 0 , if found check if the boundary elements are not valid then dont add count
    // if the boundary elements are present then increment the count and if a 0 is found set all the nearby zeroes to 1
    void dfs(int i,int j,vector<vector<int>>& grid){
        int row=grid.size();
        int col=grid[0].size();
        if( i<0 || j<0 || i>row-1 || j>col-1 || grid[i][j]!=0) return;
        grid[i][j]=-1;
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int row = grid.size(),col = grid[0].size(),count=0; 
        for(int i =0;i<row;i++)
            for(int j=0;j<col;j++)
                if((i==0 || j==0 || i==row-1 || j==col-1) && grid[i][j]==0)
                dfs(i,j,grid);
         for(int i =0;i<row;i++)
            for(int j=0;j<col;j++)
                if(grid[i][j]==0){
                    dfs(i,j,grid);
                    count++;
                }
        return count;
    }
    /*
    void dfs(int i,int j,vector<vector<int>> &grid){
        grid[i][j]=0;
        int row = grid.size();
        int col = grid[0].size();
        for(int k=0;k<4;i++){
            int ci = DR[k]+i;
            int cj = DR[k]+j;
            if(validIndex(ci,cj,grid))  
                return 1 + dfs(ci,cj,grid);
            return 0;
        }
        
    }*/
};