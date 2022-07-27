class Solution {
public:
    int numSquares(int n) {
        //vector for updating the dp array/values
        vector<int> dp(n+1,INT_MAX);
        // base case
        dp[0]=0;
        int count = 1;
        while(count*count <= n){
            int sq = count*count;
            // run from the start of the square value and then run till n+1
            for(int i = sq ; i < n+1 ; i++){
                // store in dp the min value of the prev value and current value
                // i.e. i-sq => min(1,4) -> 1
                dp[i] = min(dp[i-sq] + 1, dp[i]);
            }
            count++; // 1 , 4, 9, ...
        }
        return dp[n];
    }
};
/*
Time complexity: O(n*sqrt(n)) outer loop is of sqrt(n) iterations and in the inner loop <n iterations roughly.

Space Complexity: O(n).

*/