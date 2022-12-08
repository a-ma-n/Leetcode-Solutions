from collections import deque

class Solution:
    def floodFill(self, image: List[List[int]], row: int, col: int, newColor: int) -> List[List[int]]:
        
        height,width=len(image),len(image[0])
        sourceColor=image[row][col]
        def bfs(currentRow,currentColumn,sourceColor,newColor):
            queue=deque([])
            queue.append((currentRow,currentColumn))
            print("1")
            while queue:
                currentRow,currentColumn=queue.popleft()
                for extendedRow,extendedCol in [(-1,0),(1,0),(0,1),(0,-1),(0,0)]:
                    newRow=currentRow+extendedRow
                    newCol=currentColumn+extendedCol
                    if not 0<=newRow<height or not 0<=newCol<width or image[newRow][newCol]!=sourceColor or image[newRow][newCol]==newColor:
                        continue
                    print("exec")
                    image[newRow][newCol]=newColor
                    queue.append((newRow,newCol))
                    
                
        
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
            
        bfs(row,col,sourceColor,newColor) 
        return image



        
        