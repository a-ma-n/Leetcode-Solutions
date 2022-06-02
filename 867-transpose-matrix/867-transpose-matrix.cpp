class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> tp( matrix[0].size(),vector (matrix.size(), 0) );
        
        for(int i=0;i<matrix.size();i++){
                for(int j=0;j<matrix[0].size();j++){
                    tp[j][i]=matrix[i][j];
                }    
        }
        return tp;
    }
};