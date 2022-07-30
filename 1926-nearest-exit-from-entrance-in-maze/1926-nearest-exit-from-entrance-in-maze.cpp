class Solution {
public:
    // BFS traversal
    int dir[5]={0,-1,0,1,0};
    int nearestExit(vector<vector<char>>& maze, vector<int>& e) {
        queue<pair<int,int>> q;
        q.push({e[0],e[1]});
        
        // current moves
        int row = maze.size();
        int cols = maze[0].size();
        int moves = 1;
        
        // vector to move in all directions
        vector<vector<int>> offsets = {{0,1},{1,0},{0,-1},{-1,0}}; 
        
        // mark the entrance as visited
        maze[e[0]][e[1]] = '+';
        while(!q.empty()){
            int l = q.size();
            // for every node in the queue visit all of it's adjacent nodes which are not visited yet
            for(int k =0; k<l ; k++){
                auto [i,j] = q.front();
                q.pop();
                
                for(int l = 0 ; l<4;l++){
                    int x = i + offsets[l][0];
                    int y = j + offsets[l][1];
                    // an invalid move
                    if(x<0 || y<0 || x>=row || y >=cols || maze[x][y]=='+')
                        continue;
                    
                    // if we have reached exit then current moves are the mon moves to reach exit
                    if(x==0 || y==0 || x==row-1 || y==cols-1)
                        return moves;
                    
                    // block the cell we have visited
                    maze[x][y]='+';
                    q.push({x,y});
                }
            }
            // increment the moves
            moves++;
        }
        return -1;
    }
};