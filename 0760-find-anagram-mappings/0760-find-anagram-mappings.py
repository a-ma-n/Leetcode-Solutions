class Solution:
    def anagramMappings(self, nums1: List[int], nums2: List[int]) -> List[int]:
        mp=defaultdict(list)
        
        for i,j in enumerate(nums2):
            mp[j].append(i)
        ans=[]
        for i in nums1:
            temp=mp[i].pop()
            ans.append(temp)
        
        return ans