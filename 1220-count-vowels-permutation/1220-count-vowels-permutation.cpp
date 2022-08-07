class Solution {
public:
    /*
     Let us visualize this as a graph problem. From the above rules, we can create a directed graph where an edge between          characters first and second imply that it is permissible to write second immediately after first. Hence, the question                converts to, Given a directed graph, how many paths of length n are there?
    */
    int countVowelPermutation(int n) {
        vector<vector<long>> dp(n+1,vector<long>(5,0));
        int MOD = 1e9+7;
        /* dp[i][j] denotes the number of valid strings of length i */
        for(int i = 0 ; i < 5 ; i++)
            dp[1][i]=1; // all strings are of atleast length 1
        
        for( int i = 1 ; i< n ; i++){
            //a  inedges = e,i,u                 
            dp[i+1][0]  = (dp[i][1] + dp[i][2] + dp[i][4])%MOD;
            //e  inedges = a,i          
            dp[i+1][1]  = (dp[i][0] + dp[i][2])%MOD;
            //i  inedges = e,o                 
            dp[i+1][2]  = (dp[i][1] + dp[i][3])%MOD;
            //o  inedges = i      
            dp[i+1][3]  = dp[i][2] ;
            //u  inedges = i ,o    
            dp[i+1][4]  = (dp[i][2] + dp[i][3])%MOD ;
        }
        int res = 0 ; 
        for( int i = 0 ; i < 5; i++)
            res  = (res+dp[n][i]) % MOD;
        return res;
    }
};