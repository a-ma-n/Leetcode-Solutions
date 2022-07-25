class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        // if(!matrix.size())
        //     return false;  
        // high =n^2 -> prevents overflow
        int mid,high=matrix[0].size()*matrix.size()-1,low=0,r,c,no_of_rows=matrix[0].size();
        
        while(high>=low){
            mid=low+(high-low)/2;
            r=mid/no_of_rows;
            c=mid%no_of_rows;
            if(target==matrix[r][c]){
                return true;
            }
            else if(target>matrix[r][c]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        
        return false;
    }
};