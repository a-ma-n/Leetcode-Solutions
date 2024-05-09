class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        scoreSorted=sorted(score,reverse=True)
        ans=[]
        rank=4
        mp=dict()
        for i,j in enumerate(scoreSorted):
            
            if i==0:res="Gold Medal"
            elif i==1:res="Silver Medal"
            elif i==2:res="Bronze Medal"
            else:
                res=str(rank)
                rank+=1
            mp[j]=res
        for i in score:
            ans.append(mp[i])
        return ans