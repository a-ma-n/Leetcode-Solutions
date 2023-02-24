class Solution:
    def findMaximizedCapital(self, k: int, w: int, profits: List[int], capital: List[int]) -> int:
        n=len(profits)
        
        projects=list(zip(capital,profits))
        # sorted on capital => so we start with always the min value i.e. 0
        projects.sort()
        
        q=[]
        ptr=0
        for i in range(k):
            while ptr<n and projects[ptr][0] <=w:
                heappush(q,-projects[ptr][1])
                ptr+=1
            if not q:
                break
            w+=-heappop(q)
        return w
        