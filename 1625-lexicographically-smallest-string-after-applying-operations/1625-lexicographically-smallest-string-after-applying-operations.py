class Solution:
    def findLexSmallestString(self, s: str, a: int, b: int) -> str:
        rec=set()
        def dfs(s):
            if s in rec:
                return
            rec.add(s)
            dfs(s[-b:]+s[:-b])
            dfs("".join([str((int(c)+a*(i%2))%10) for i,c in enumerate(s)]))
        
        dfs(s)
        return min(rec)