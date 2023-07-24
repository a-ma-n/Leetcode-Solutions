class Solution:
    
    def numberOfWays(self, n: int, x: int) -> int:
        mem = dict()
        
        def recur(val, total):
            key = (val, total)
            if key in mem:
                return mem[key]
            
            if total == 0:
                return 1
            
            if total < 0 or val <= 0:
                return 0
            
            temp1 = recur(val - 1, total - (val ** x))
            temp2 = 0
            if val - 1 != 0:
                temp2 = recur(val - 1, total) % (1_000_000_000 + 7)
            
            mem[key] = temp1 + temp2
            
            return mem[key]
        
        return recur(n, n)
