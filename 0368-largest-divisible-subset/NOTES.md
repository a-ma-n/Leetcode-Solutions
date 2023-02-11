cannot use @cache with global variables as the values are going to be stored for params irrespective of the global variables
not a correct way
```
from functools  import cache
class Solution:
# temp=[]
# ans=[]
def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
nums.sort()
n=len(nums)
temp=[]
ans=[]
# @cache
def traverse(ind,prev_ind):
if ind==n:
if len(temp)!=0:
ans.append(temp.copy())
return 0
notPick=traverse(ind+1,prev_ind)
pick=0
if prev_ind==-1 or nums[ind]%nums[prev_ind]==0:
temp.append(nums[ind])
pick=1+traverse(ind+1,ind)
temp.pop()
return max(pick,notPick)
traverse(0,-1)
maxLen=0
tempAns=ans[0]
print(ans)
for i in ans:
if len(i)>maxLen:
maxLen=len(i)
tempAns=i
# self.ans.clear()
# self.temp.clear()
return tempAns
```