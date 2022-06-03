class NumMatrix {
public:
    vector<vector<int>> mat;
    NumMatrix(vector<vector<int>>& matrix) {
        //Presum of each row...
        for(int i=0;i<matrix.size();i++) {
            for(int j=1;j<matrix[0].size();j++) {
                matrix[i][j]+=matrix[i][j-1];
            }
        }
        
        //Presum of each col...
        for(int i=1;i<matrix.size();i++) {
            for(int j=0;j<matrix[0].size();j++) {
                matrix[i][j]+=matrix[i-1][j];
            }
        }
        
        //Our Presum Matrix
        mat = matrix;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
		//Sum of elements till row2 and col2 (green rectangle)
        int sum = mat[row2][col2];
        
		//Redundant elements (elements in blue rectangles - elements in white ellipse)
        int extra = ((row1==0)?0:mat[row1-1][col2]) + ((col1==0)?0:mat[row2][col1-1]) - ((row1!=0 && col1!=0)?mat[row1-1][col1-1]:0);

        return sum-extra;
    }
};