class Solution:
    def reorderedPowerOf2(self, n: int) -> bool:
        nums = []
        x = 1
        temp = Counter(str(n))
        print(temp)
        while x<=10**9:
            cur = Counter(str(x))
            print(cur)
            if temp==cur:
                return True
            x*=2
        
        return False