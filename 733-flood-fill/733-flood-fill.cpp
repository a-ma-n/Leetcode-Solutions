#include <queue>
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int x, int y, int newColor) {
        int oldColor  = image[x][y],i,j ;
        int m = image.size(),n=image[0].size();
        queue<pair<int,int>> q;
        q.push({x,y});
        while(!q.empty()){
            auto pixel = q.front();
            i = pixel.first;
            j = pixel.second;
            q.pop();
            
            if( i<m && j<n && i>=0 && j>=0){
                if (image[i][j] == oldColor && image[i][j] != newColor)
                {
                image[i][j]=newColor;
                q.push({i+1,j});
                q.push({i-1,j});
                q.push({i,j+1});
                q.push({i,j-1});
                }
            }
        }
        return image;
}
        
    
};