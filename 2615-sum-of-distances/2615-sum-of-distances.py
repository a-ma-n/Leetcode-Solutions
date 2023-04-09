class Solution:
    def distance(self, nums: List[int]) -> List[int]:
        mp=defaultdict(list)
        for i,j in enumerate(nums):
            mp[j].append(i)
        
        ans=[0]*len(nums)
        for key,val in mp.items():
            # for key,val in d1.items():
            suffixSum=sum(val)#suffix sum
            prefixSum=0#prefix sum
            suffixLength=len(val)#len(suffix)
            prefixLength=0#len(pre)
            for i in val:#iterate in the indexes value like [0,2,3]:
                prefixSum+=i 
                prefixLength+=1
                suffixSum-=i
                suffixLength-=1
                ans[i]=(-prefixSum+prefixLength*i-suffixLength*i+suffixSum) #ans[0]=(-0+1*0-2*0+5)=5
        return ans