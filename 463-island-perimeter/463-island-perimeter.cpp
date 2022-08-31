class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int result=0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    result+=4;
                    int temp=result;
                    if(i!=0 && grid[i-1][j]==1)
                        result--;
                    if(i!=m-1 && grid[i+1][j]==1)
                        result--;
                    if(j!=0 && grid[i][j-1]==1)
                        result--;
                    if(j!=n-1 && grid[i][j+1]==1)
                        result--;
                    if(temp==result)
                        return result;
                }        
            }
        }
        return result;
    }
};