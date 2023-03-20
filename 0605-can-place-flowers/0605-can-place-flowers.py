class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        count=0
        # if flowerbed[i-1]==flowerbed[i] and flowerbed[i]==0:
        #     count+=1
        #     flowerbed[i]=1
        
            
        for i in range(len(flowerbed)):
            center=flowerbed[i]
            right=left=-1
            if len(flowerbed)==1: return flowerbed[i]==0 and n<=1 or  flowerbed[i]==1 and n==0
            
            if i==0:
                right=flowerbed[i+1]
            elif i==len(flowerbed)-1:
                left=flowerbed[i-1]
            else:
                left=flowerbed[i-1]
                right=flowerbed[i+1]
                
            if left==-1 and center==right and center==0:
                flowerbed[i]=1
                count+=1
            elif right==-1 and center==left and center==0:
                flowerbed[i]=1
                count+=1
            elif left==center and center==right and center==0:
                flowerbed[i]=1
                count+=1
        return count>=n
            