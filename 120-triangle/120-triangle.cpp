class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        //We can easily see that directly just choosing the minimum value in the next row(amongst triangle[nextRow][i] and triangle[nextRow][i+1]) won't fetch us the optimal final result since it maybe the case that the latter values of previous chosen path turn out to be huge.
        
        /*
        We chose to go from top-level to the bottom-level of triangle in the previous approach. We can also choose to start from the bottom of triangle and move all the way to the top. We will again follow the same DP strategy as used in the above solution.

At each cell of the triangle, we could have moved here from the below level in 2 ways, either from -

the same index i in below row, or
the index i+1.
And again, we will choose the minimum of these two to arrive at the optimal solution. Finally at last, we will reach at triangle[0][0], which will hold the optimal (minimum) sum of path.

Actually, this approach will make the code a lot more clean and concise by avoiding the need of bound checks.

        */
        
        
        
        
        //we modify the given triangle 2d vector
        for(int level = size(triangle) - 2;level>=0;level--)
            for(int i = 0 ;i<=level;i++)
                triangle [level][i] += min(triangle[level+1][i],triangle[level+1][i+1]);
        return triangle[0][0];
        

        
        
            
        }   
};

//      Bottom up with aux space   & no i/p modification
        
//        int minimumTotal(vector<vector<int>>& triangle) {
// 	int n = size(triangle), level = 1;
////////-> init 2 values as vectors
// 	vector<vector<int> > dp(2, vector<int>(n, INT_MAX));
// 	dp[0][0]=triangle[0][0];  // assign top-most row to dp[0] as we will be starting from level 1
// 	for(; level < n; level++) 
// 		for(int i = 0; i <= level; i++)
// 			dp[level & 1][i] = triangle[level][i] + min(dp[(level - 1) & 1][min(i, n - 1)], dp[(level - 1) & 1][max(i - 1, 0)]); 
// 	level--; // level becomes n after for loop ends. We need minimum value from level - 1
// 	return *min_element(begin(dp[level & 1]), end(dp[level & 1])); 
// }
        