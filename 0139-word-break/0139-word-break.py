class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        
        n=len(s)
        s+=" "
        @cache
        def recur(ind):
            # print(ind,s[:ind])
            if ind>=n: return True
            
            pick=False
            for k in range(ind,n+1):
                # print(ind,s[ind:k+1])
                if s[ind:k+1] in wordDict:
                    if recur(k+1):
                        pick=True
                        
            return pick
        return recur(0)