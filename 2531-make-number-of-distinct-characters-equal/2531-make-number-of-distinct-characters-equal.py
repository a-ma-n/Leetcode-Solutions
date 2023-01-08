class Solution:
    def isItPossible(self, word1: str, word2: str) -> bool:
        a,b = Counter(word1),Counter(word2) 
        c,d = a.copy(),b.copy()
        for i in a: 
            for j in b: 
                c[i], c[j], d[j], d[i] = c[i]-1, c[j]+1, d[j]-1, d[i]+1
                if not c[i]: del c[i] 
                if not d[j]: del d[j] 
                if len(c)==len(d): return True #after swap 
                c,d = a.copy(),b.copy() 
        return False