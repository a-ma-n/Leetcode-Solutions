class Solution {
public:
    int maxProfit(vector<int>& Arr, int fee) {
        int n = Arr.size();
        if(n==0) return 0;
        vector<vector<int>> dp(n+1,vector<int>(2,0)); // n+1 = nth index becomes available
        
        for(int ind = n-1;ind>=0;ind--){
            for(int buy = 0 ; buy <=1;buy++){
                int profit;
                if(buy==0){
                    profit=max(
                        0+dp[ind+1][0],// not buying => can buy in next steps
                -Arr[ind]+dp[ind+1][1] // buying => cannot buy in next steps
                              );
                }
                if(buy==1){
                    profit= max(
                        0+dp[ind+1][1], // not selling => cannot buy in next steps
                        Arr[ind]-fee+dp[ind+1][0] //  selling => can buy in next steps
                    );
                }
                dp[ind][buy] = profit;
            }
        }
        return dp[0][0];
    }
        
};
