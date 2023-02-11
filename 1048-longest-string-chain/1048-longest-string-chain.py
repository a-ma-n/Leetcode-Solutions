class Solution:
    def longestStrChain(self, arr: List[str]) -> int:
        
        def isAscending(w1,w2):
            l1,l2=len(w1),len(w2)
            if l1!=l2+1: return False
            first,second=0,0
            while first<l1:
                if second<l2 and w1[first]==w2[second]:
                    first+=1
                    second+=1
                else:
                    first+=1
            # print(first == l1 and second == l2)
            return first == l1 and second == l2
                    
        n=len(arr)
        arr=sorted(arr,key=len)
        dp=[1]*(n)
        hash=[1]*(n)
        for ind in range(n):
            hash[ind]=ind
            for prev_ind in range(0,ind):
                if isAscending(arr[ind],arr[prev_ind]) and 1+dp[prev_ind]>dp[ind]:
                    dp[ind]=1+dp[prev_ind]
                    hash[ind]=prev_ind
        ans,lastIndex=-1,-1
        for ind in range(n):
            if dp[ind]>ans:
                ans=dp[ind]
                lastIndex=ind
        return ans
#         temp=[]
#         temp.append(arr[lastIndex])
#         while hash[lastIndex]!=lastIndex:
#             lastIndex = hash[lastIndex]
#             temp.append(arr[lastIndex])   
#         return reversed(temp)
        