class Solution:
    def combinationSum2(self, c: List[int], target: int) -> List[List[int]]:
        N = len(c)
        c.sort()  # Sort the candidates list
        
        def recur(ind, t, combn):
            if t == 0:
                self.combinations.append(combn.copy())
                return
            
            for i in range(ind, N):
                if c[i] > t:
                    break
                
                if i > ind and c[i] == c[i-1]:  # Skip duplicate values
                    continue
                
                combn.append(c[i])
                recur(i + 1, t - c[i], combn)
                combn.pop()
        
        self.combinations = []
        recur(0, target, [])
        
        return self.combinations