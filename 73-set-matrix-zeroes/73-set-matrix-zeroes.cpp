class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool top=false;
        bool right=false;
        int rows=matrix.size(),cols=matrix[0].size();
        
       
        
        for(int i = 0 ; i<cols;i++){
            // topmost col check
            if(matrix[0][i]==0){ 
                top=true;
                break;
            }
        }
        
        for(int i = 0 ; i<rows;i++)
            {
            // rightmost col check
            if(matrix[i][cols-1]==0) {
                 right=true;
                // break;
            }
        }
        
        for(int i=1;i<rows;i++){
            for(int j=0;j<cols-1;j++){
                if(matrix[i][j]==0){
                    matrix[0][j]=0;
                    matrix[i][cols-1]=0;
                }
            }
        }
        
        for(int i=rows-1;i>0;i--){
            for(int j = cols-2;j>=0;j--){
                if(matrix[0][j]==0) matrix[i][j]=0;
                if(matrix[i][cols-1]==0) matrix[i][j]=0;
            }
        }
        // loop to set top row and rightmost col 0 if there was originally a zero there
        if(top){
            for(int i = 0 ; i < cols ; i++ ){
                matrix[0][i]=0;
            }
        }
        if(right){
            for(int i = 0 ; i < rows ; i++ ){
                matrix[i][cols-1]=0;
            }
        }
        //cout<<top0<<endl<<right0;
        
    }
};