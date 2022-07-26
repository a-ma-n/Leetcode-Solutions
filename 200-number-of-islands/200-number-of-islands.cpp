class Solution {
public:
    // visit islands and then set them to 0 and visit the next nodes and then do BFS on every node
     int DR[4]={1, 0, -1, 0};
    int DC[4]={0, -1, 0, 1};
    
    bool validIndex(int x,int y,int row,int col){
        if( x >=0 && y >=0 && x<row && y<col ) return true;
        return false;
    }
    void bfs(int i, int j, vector<vector<char>>& grid) {
        int row= grid.size(),col=grid[0].size(); 
        grid[i][j]='0';
        queue<pair<int, int>> q;
        q.push({i, j});
        while(!q.empty()) {
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for(int k=0; k<4; k++) {
                int ci=DR[k]+i;
                int cj=DC[k]+j;
                if(!validIndex(ci, cj, row,col))
                    continue;
                if(grid[ci][cj]=='1') {
                    q.push({ci, cj});
                    grid[ci][cj]='0';
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int x,y,count=0;
        int row= grid.size(),col=grid[0].size(); 
        for( int i =0 ; i<row ; i++ ){
            for( int j =0; j<col ;j++ ){
                if(grid[i][j]=='1'){
                    count++;
                    bfs(i,j,grid);
                }
            }
        }
        return count;
    }
};