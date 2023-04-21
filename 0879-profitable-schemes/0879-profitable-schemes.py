class Solution:
    def profitableSchemes(self, n: int, minProfit: int, group: List[int], profit: List[int]) -> int:
        
        MOD = 10**9 + 7
        dp = [[0] * (n + 1) for i in range(minProfit + 1)]
        dp[0][0] = 1
        for g, p in zip(group, profit):
            for i in range(minProfit, -1, -1):
                for j in range(n - g, -1, -1):
                    dp[min(i + p, minProfit)][j + g] += dp[i][j]
                    dp[min(i + p, minProfit)][j + g] %= MOD
        return sum(dp[minProfit]) % MOD