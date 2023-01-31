class Solution:
    #bottom up approach
    def bestTeamScore(self, scores: List[int], ages: List[int]) -> int:
        players=list(sorted(zip(ages,scores)))
        print(players)
        N=len(players)
        ans=max(scores)
        dp=deepcopy([p[1] for p in players])
        for i in range(N):
            for j in range(i):
                if players[j][1] <= players[i][1]:
                    dp[i] = max(dp[i], dp[j] + players[i][1])
            ans=max(ans,dp[i])
        return ans