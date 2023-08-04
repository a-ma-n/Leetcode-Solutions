class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        
        n=len(s)
        s+=" "
        @cache
        def recur(ind):
            if ind<0: return True

            isAnyTrue=False
            for k in range(ind,-1,-1):
                # print(s[k:ind+1])
                if s[k:ind+1] in wordDict:
                    if recur(k-1):
                        isAnyTrue=True

            return isAnyTrue
        return recur(n-1)
            
        dp=[0]*n
        # @cache
#         def recur(ind):
#             if ind>=n: return True
            
#             isAnyTrue=False
#             for k in range(ind,n+1):
#                 if s[ind:k+1] in wordDict:
#                     if recur(k+1):
#                         isAnyTrue=True
                        
#             return isAnyTrue
#         return recur(0)
    
            
    
    
        
        
        
        