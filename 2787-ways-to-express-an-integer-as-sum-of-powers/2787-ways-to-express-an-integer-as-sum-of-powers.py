class Solution:
    # @cache
    def numberOfWays(self, n: int, x: int) -> int:
        # val=n**(1/x)+1
        # @lru_cache(maxsize=50000)
        @lru_cache(maxsize=10000)
        def recur(val,total):            
            if total==0: return 1
            if total<0 or val<=0: return 0 
            # temp1=0
            # if val-1==
            temp1=(recur(val-1,total-(val**x)))
            temp2=0
            if val-1!=0:
                temp2=recur(val-1,total)%(1_000_000_000+7)
            return  temp1 + temp2
        return (recur(n,n))
        
#         # bottom up


#         dp=[[0 for _ in range(n+1)] for _ in range(n+1)]
    
# #         # base case fill 0 indices
        
#         for i in range(n):
#             dp[i][0]=1
    
#         for v in range(1,n+1):
#             for t in range(1,n+1):
#                 if dp[t]+v**x==:
#                     dp[t]=1+dp[t-v]
#                 dp[v][t]=max(dp[v-1][t],dp[v][t-1])
#         print(dp)
#         maxval=0
#         for i in range(n):
#             maxval=max(maxval,dp[i][n])
#         return maxval
        
        
#         return cnt