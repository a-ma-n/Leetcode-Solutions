class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        c1,c2=Counter(s1.split()),Counter(s2.split())
        s1=set([ k for k,v in c1.items()])
        s2=set([ k for k,v in c2.items()])
        
        ans= (s1.difference(s2)).union(s2.difference(s1))
        finalAns=[]
        # print(ans,1,c2)
        for i in ans:
            if i in c1:
                if c1[i]==1: finalAns.append(i)
            if i in c2:
                if c2[i]==1: finalAns.append(i)
        return finalAns
        