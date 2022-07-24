class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        bool found = false;
        
        for(int i =0;i<rows;i++){
            int low=0,high=cols-1,mid;
            if(matrix[i][low]==target) return true;
            
            cout<<low<<" "<<high;
            if(matrix[i][high]==target) return true;
            while(low<=high){
                mid = (low+high) /2;
                if(matrix[i][mid]==target){
                    return true;
                    break;
                }
                else if(matrix[i][mid]<target){
                    low=mid+1;
                }
                else if(matrix[i][mid]>target) {
                    high = mid-1;
                }
            }
        }
        return false;
        
    }
};