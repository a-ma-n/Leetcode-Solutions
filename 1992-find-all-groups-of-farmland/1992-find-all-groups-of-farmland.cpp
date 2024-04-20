class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<bool>> visited(land.size(), vector<bool>(land[0].size(), false));
        vector<vector<int>> ans;
        for (int row1 = 0; row1 < land.size(); row1++) {
            for (int col1 = 0; col1 < land[0].size(); col1++) {
                if (land[row1][col1] && !visited[row1][col1]) {
                    int row2 = 0, col2 = 0;
                    DFS(land, visited, row1, col1, row2, col2);
                    ans.push_back({row1, col1, row2, col2});
                }
            }
        }
        
        return ans;
    }

private:
    // The four directions in which traversal will be done.
    int dirs[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    // Returns true if the coordinate is within the boundary of the matrix.
    bool isWithinFarm(int x, int y, int N, int M) {
        return x >= 0 && x < N && y >= 0 && y < M;
    }
    
    void DFS(vector<vector<int>>& land, vector<vector<bool>>& visited, int x, int y, int& row2,
        int& col2) {
        visited[x][y] = true;
        // Maximum x and y for the bottom right cell.
        row2 = max(row2, x); col2 = max(col2, y);
        
        for (auto dir : dirs) {
            // Neighbor cell coordinates.
            int newX = x + dir[0], newY = y + dir[1];
            // If the neighbor is within the matrix and is a farmland cell and is not visited yet.
            if (isWithinFarm(newX, newY, land.size(), land[0].size()) && !visited[newX][newY]
                    && land[newX][newY]) {
                DFS(land, visited, newX, newY, row2, col2);
            }
        }
    }    
};
 