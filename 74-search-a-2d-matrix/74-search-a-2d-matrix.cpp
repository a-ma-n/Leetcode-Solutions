class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size(),cols=matrix[0].size();
        int min_diff=abs(target-matrix[0][0]);
        int diff=0,p=0;
        
        for(int i=0;i<rows;i++){
            //diff=abs(target-matrix[i][0]);
            
            if(target>= matrix[i][0]  ){
                p=i;
            }
        }
        cout<<"p:"<<p<<endl;
        cout<<"min diff:"<<min_diff;
        
        
        for(int i=0;i<cols;i++){
            
            if(matrix[p][i]==target){
                return true;
            }
        }
        return false;
        
        // int high=matrix[0].size()-1,low=0,mid;
        // while(high>=low){
        //     mid=(high+low)/2;
        //     if(matrix[p][mid]==target){
        //         return true;
        //     }
        //     else if(target>matrix[p][mid])
        // }
        // return false;
        
    }
};