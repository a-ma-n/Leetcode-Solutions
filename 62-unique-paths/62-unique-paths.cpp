class Solution {
public:
    int uniquePaths(int m, int n) {
        
        int N = n + m - 2; 
        int r = min(m-1,n-1);
        
        double res =1;
        for(int i=1;i<=r;i++){
            res=res*(N-r+i)/i;
        }
        
        return (int)res;
    }
};


// Recursion

//  int _uniquePaths(int i,int j,int m, int n) {
//         //base case
//         // if we reach the end
//         if(i==m-1 && j==(n-1))
//             return 1;
//         //if we end up outside the matrix
//         if(i>=m || j>=n)
//             return 0;
        
//         return (_uniquePaths(i+1,j,m,n) + _uniquePaths(i,j+1,m,n));
//      }

// DP
// int countPaths(int i,int j,int n,int m, vector<vector<int>>&dp){
//         if(i==(n-1) && j==(m-1))
//             return 1;
//         if(i>=n || j>=m)
//             return 0;
        
//         if(dp[i][j]!=-1)
//             return dp[i][j];
//         else 
//             return dp[i][j] = countPaths(i+1,j,dp) +countPaths(i,j+1,dp);
//     }


