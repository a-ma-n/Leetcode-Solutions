class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        # spells.sort()
        potions.sort()
        
        # assuming len_spells<len_potions 
        n=len(potions)
        
        
        
        # binary search fn
        
        def binary_search(i):
            low,high=0,n-1
            while low<=high:
                mid=low+(high-low)//2
                if potions[mid]*i>=success:
                    if mid==0:
                        # print(i,n)
                        return n
                    elif potions[mid-1]*i>=success:
                        # print(mid)
                        high=mid-1
                    else:
                        # print(i,'i',mid)
                        return n-mid
                else:
                    low=mid+1
            return 0
                    
        
        
        
        possible_combns=[]
        for i in spells:
            possible_combns.append(binary_search(i))
        return possible_combns
        