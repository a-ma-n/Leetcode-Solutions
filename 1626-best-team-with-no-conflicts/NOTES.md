#memoised approach
def bestTeamScore(self, scores: List[int], ages: List[int]) -> int:
players=list(sorted(zip(ages,scores)))
maxScore=players[0][1]
@lru_cache(1000)
def findMaxScore(prev,ind):
if ind>=len(players): return 0
if (prev == -1 or players[ind][1] >= players[prev][1]):
return max(findMaxScore( prev, ind + 1), players[ind][1] + findMaxScore( ind, ind + 1))
return findMaxScore(prev,ind+1)
ans=findMaxScore(-1,0)
return ans
---
[(1, 5), (8, 1), (9, 2), (10, 3)]
[1, 2, 4, 7] [1, 2, 3, 5]
​
[(1, 5), (8, 1), (9, 2), (10, 3)]
[5, 1, 3, 6] [1, 2, 3, 5]