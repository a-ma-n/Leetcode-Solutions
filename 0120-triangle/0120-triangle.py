class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        
        @cache
        def traverse(i,j):
            if j>=len(triangle): 
                return float(inf)
            if i==len(triangle)-1: 
                return triangle[i][j]
            print(triangle[i][j])
            return triangle[i][j]+min(traverse(i+1,j),traverse(i+1,j+1))
        return traverse(0,0)