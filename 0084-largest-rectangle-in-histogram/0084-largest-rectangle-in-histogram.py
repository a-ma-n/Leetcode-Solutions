class Solution:
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