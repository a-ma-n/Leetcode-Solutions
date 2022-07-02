class Solution {
public:
    int minPathSum(vector<vector<int>>& matrix) {
        // m => rows, n=>cols
        int n=matrix.size(),m=matrix[0].size();
        vector<int> prev(m,0);
        
        for(int i=0; i<n ; i++){
            vector<int> temp(m,0);
            
            for(int j=0; j<m ; j++){
                 if(i==0 && j==0) temp[j] = matrix[i][j];
                 else{
                    
                    int up = matrix[i][j];
                     
                    if(i>0) up += prev[j];
                    else up += 1e9;

                    int left = matrix[i][j];
                     
                    if(j>0) left+=temp[j-1];
                    else left += 1e9;

                    temp[j] = min(up,left);
                 }
            }
            prev=temp;
        }
            return prev[m-1];
        }
};