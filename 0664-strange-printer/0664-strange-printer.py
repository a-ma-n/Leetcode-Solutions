class Solution:
    def strangePrinter(self, s: str) -> int:
        @cache
        def solve(s):
            if not s:
                return 0
            # not free
            cost = solve(s[:-1])+1
            
            # free
            char_to_use=s[-1]
            
            for i,v in enumerate(s[:-1]):
                if v==char_to_use:
                    cost = min(cost,solve(s[:i+1]) + solve(s[i+1:-1]))
            
            return cost
        
        return solve(s)