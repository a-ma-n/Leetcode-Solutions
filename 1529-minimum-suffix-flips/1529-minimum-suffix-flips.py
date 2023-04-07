class Solution:
    def minFlips(self, target: str) -> int:
        # odd flips => 1,even =>0
        allZeroes=True
        for ind,i in enumerate(target):
            if i!='0':
                # remove trailing zeroes
                target=target[ind:]
                allZeroes=False
                break
        if allZeroes: return 0
        
        target+=" "
        cnt=0
        for i in range(1,len(target)):
            if target[i]!=target[i-1]:
                cnt+=1
        return cnt