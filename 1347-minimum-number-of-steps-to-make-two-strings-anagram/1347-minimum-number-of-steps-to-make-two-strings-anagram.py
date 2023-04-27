class Solution:
    def minSteps(self, s: str, t: str) -> int:
        cnt,steps=Counter(s),0
        for i in t:
            if cnt[i]>0:
                cnt[i]-=1
            else:
                steps+=1
        return steps
            