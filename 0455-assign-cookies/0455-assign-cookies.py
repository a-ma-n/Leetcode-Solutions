class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g.sort()
        s.sort()
        i=j=cnt=0
        visited=set()
        while i<len(g):
            while j<len(s):
                if s[j]>=g[i] and j not in visited:
                    cnt+=1
                    visited.add(j)
                    break
                j+=1
            i+=1
        return cnt