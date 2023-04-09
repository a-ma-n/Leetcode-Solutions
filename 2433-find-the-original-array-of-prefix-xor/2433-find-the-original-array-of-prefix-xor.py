class Solution:
    def findArray(self, pref: List[int]) -> List[int]:
        ans=[0]*len(pref)
        ans[0]=pref[0]
        carryM=1
        for i in range(len(pref)-1,0,-1):
            pref[i]^=pref[i-1]
            ans[i]=pref[i]
        return ans