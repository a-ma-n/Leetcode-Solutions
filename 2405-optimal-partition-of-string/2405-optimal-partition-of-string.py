class Solution:
    def partitionString(self, s: str) -> int:
        sub_set,ans=set(),1
        for c in s:
            if c in sub_set:
                ans+=1
                sub_set={c}
            else:
                sub_set.add(c)     
        return ans