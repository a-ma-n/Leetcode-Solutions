#include <queue>
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int x, int y, int newColor) {
         int oldColor = image[x][y];

    // Number of rows.
    int m = image.size();

    // Number of columns.
    int n = image[0].size();

    // Queue to hold the coordinates of the pixels.
    queue<pair<int, int>> q;

    q.push({x, y});

    while (!q.empty())
        {
        pair<int, int> currentPixel = q.front();
        q.pop();

        // i and j represent the row and column of the current pixel.
        int i = currentPixel.first;
        int j = currentPixel.second;


        // Check if the current coordinates are valid.
        if (i >= 0 && i < m && j >= 0 && j < n)
        {
            // Now, check if the current pixel has been colored or not.
            if (image[i][j] == oldColor && image[i][j] != newColor)
            {
                // So, replace the old colour.
                image[i][j] = newColor;

                // Push the adjacent pixels into the queue.
                q.push({i, j + 1});
                q.push({i, j - 1});
                q.push({i + 1, j});
                q.push({i - 1, j});
            }
        }
    }

    return image;
}
        
    
};