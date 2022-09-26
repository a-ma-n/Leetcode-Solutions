from collections import deque

class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        
        h,w=len(image),len(image[0])
        
        def dfs(cur_r,cur_c,src_color,new_color):
                        
            if cur_r<0 or cur_r>=h or cur_c<0 or cur_c>=w or image[cur_r][cur_c]==newColor or image[cur_r][cur_c]!=src_color:
                return
            
            # update color
            image[cur_r][cur_c]=newColor
            
            #BFS to 4 connected neighbours
            dfs(cur_r-1,cur_c,src_color,new_color) 
            dfs(cur_r+1,cur_c,src_color,new_color) 
            dfs(cur_r,cur_c-1,src_color,new_color)
            dfs(cur_r,cur_c+1,src_color,new_color) 
        dfs(sr,sc,src_color=image[sr][sc],new_color = newColor) 
        return image



        
        