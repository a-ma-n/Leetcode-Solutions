class Solution:
    def onesMinusZeros(self, grid: List[List[int]]) -> List[List[int]]:
        rows=len(grid)
        cols=len(grid[0])
        
        onesCol,onesRow,zeroesCol,zeroesRow=[0]*cols,[0]*rows,[0]*cols,[0]*rows
        
        for row in range(len(grid)):
            for col in range(len(grid[0])):
                if grid[row][col]==0:
                    zeroesRow[row]+=1
                    zeroesCol[col]+=1
                elif grid[row][col]==1:
                    onesRow[row]+=1
                    onesCol[col]+=1
                    
        # diff=[[0]*cols]*rows
        row,col=0,0
        ans=[]
        for i in range(rows):
            res=[]
            for j in range(cols):
                # if i==2:
                #     print("r,c,diff:",i,j,diff[i][j],"\n")
                #     # return diff
                #     print("add:",onesRow[i] + onesCol[j] - zeroesRow[i] - zeroesCol[j])
                num=onesRow[i] + onesCol[j] - zeroesRow[i] - zeroesCol[j]
                res.append(num)
            ans.append(res)
            # print(res,"\n",ans)
                # diff[row][col]=num
                # print(diff,"row=",i,"col=",j,end="-\n")
        return ans
                