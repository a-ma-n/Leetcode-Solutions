class Solution:
    def addToArrayForm(self, nums: List[int], k: int) -> List[int]:
        return (list(map(int,list(str(int(''.join(list(map(str,nums))))+k)))))
#         return list(map(int,
                        
