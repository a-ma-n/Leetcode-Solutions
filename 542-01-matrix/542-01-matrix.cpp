class Solution {
public:
    /*
    Complexity Analysis:
    
    Time complexity: O(r.c)
    Space complexity: O(r.c)
    An additional O(r⋅c) space is required to maintain the queue.
    */
    // BFS Solution
    
    /*
    At the end of the day it transforms itself into a map like grid where the 1's next to 0's remain 1 only.
    And the innner 1's start increasing if they do not have 0's at the boundary.
    */
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows=mat.size();
        if(!rows) return mat; // rows==0
        int cols = mat[0].size();
        vector<vector<int>> dist(rows,vector<int> (cols,INT_MAX));
        queue<pair<int,int>> q;
        
        for(int i = 0 ;i <rows ; i++)
            for(int j = 0 ; j< cols;j++)
                if(!mat[i][j]){
                    dist[i][j]=0;
                    q.push({i,j}); // Put all o's in the queue
                }
        
        int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty()){
            pair<int,int> curr = q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int new_r = curr.first+dir[k][0],new_c = curr.second+dir[k][1];
                
            if(new_r>=0 && new_c>=0 && new_r<rows && new_c < cols){
                    if(dist[new_r][new_c] > dist[curr.first][curr.second] + 1){
                        dist[new_r][new_c] = dist[curr.first][curr.second]+1;
                                                            q.push({new_r,new_c});
                    
                }
            }
        }     
        }
             return dist;       
        
    }
};