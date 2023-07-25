class Solution:
    def peakIndexInMountainArray(self, arr: List[int]) -> int:

        low=0
        high=len(arr)-1
        while low<=high:   
            mid=low+(high-low)//2
            print(low,mid,high)
            if arr[mid+1]<arr[mid]>arr[mid-1]:
                return mid
            elif arr[mid+1]>arr[mid]:
                low=mid+1
            else:
                high=mid-1
       
        return mid
        
        # 3 4 5 1
        # 0 1 2 3 
        # l m   h
        #     l h
       