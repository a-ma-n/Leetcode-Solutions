class Solution:
    def countVowelPermutation(self, n: int) -> int:
        vow = "aeiou"
        MOD = 10**9+7
        def isAllowed(c,prev):
            if prev=="a":
                return c=="e"
            elif prev=="e":
                return c in "ai"
            elif prev=="i":
                return c!="i"
            elif prev=="o":
                return c in "iu"
            elif prev=="u":
                return c=="a"    
            return True
        
        @cache
        def solve(n,prev):
            if n==0:
                return 1
            ans = 0
            for c in vow:
                if isAllowed(c,prev):
                    ans += solve(n-1,c)            
                    if ans>=MOD:
                        ans-=MOD
            return ans
        return solve(n,"-")