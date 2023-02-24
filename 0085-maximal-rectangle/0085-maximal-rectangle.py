
class Solution:
    # lc 84
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack=[]
        maxA=0
        n=len(heights)
        for i in range(n+1):
            while stack and (i==n or heights[stack[-1]]>=heights[i]):
                height=heights[stack[-1]]
                stack.pop()
                width=0
                if not stack: width = i
                else: width=i-stack[-1]-1
                maxA=max(maxA,width*height)
            stack.append(i)
        return maxA
    
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        n,m=len(matrix),len(matrix[0])
        maxArea=0
        height=[0]*m
        # print(n,m,matrix)
        for i in range(n):
            for j in range(m):
                    if matrix[i][j]=='1' : 
                        height[j]+=1
                        # print("temp",j,height[j])
                    else: height[j]=0
                        
            area=self.largestRectangleArea(height)
            # print(height,self.largestRectangleArea(height))
            maxArea=max(maxArea,area)
        return maxArea
            
            
        