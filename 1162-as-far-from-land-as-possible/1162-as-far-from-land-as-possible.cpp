class Solution {
public:
    // bfs on each cell with value 1
    // When you can only go 4 directions, the (minimum) number of cells you travel from point A to point B is the Manhattan distance.



    int maxDistance(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size(),steps=0;
        queue<pair<int,int>>q;
        
        for(int i =0;i<r;i++)
            for(int j=0;j<c;j++)
                if(grid[i][j]==1)
                    q.push({i-1,j}),q.push({i+1,j}), q.push({i,j-1}),q.push({i,j+1});
        while(!q.empty()){
            // in every iteration we are moving 1 step in bfs from every island
            int size = q.size();
            steps++;
            for(int k=0;k<size;k++){
                int i = q.front().first,j = q.front().second;
                q.pop();
                if(i>=0&&j>=0&&i<r&&j<c&&grid[i][j]==0){
                    grid[i][j]=steps;
                    q.push({i-1,j}),q.push({i+1,j}), q.push({i,j-1}),q.push({i,j+1});
                }
                    
            }
        }
        return steps==1?-1:steps-1; // if steps=0 then also return 0-1=0,  
    }
};