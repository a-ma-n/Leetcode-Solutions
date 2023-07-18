#User function Template for python3
class Solution:
	def subsetSums(self, arr, N):
		# code here
        def recur(l,sumnow):
            # print(arr,l,N)
            if l>=N:
                # print(sumnow)
                self.a.append(sumnow)
                return
            recur(l+1,sumnow+arr[l])
            recur(l+1,sumnow)
        self.a=[]
        
        recur(0,0)
        return self.a

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    T=int(input())
    for i in range(T):
        N = int(input())
        arr = [int(x) for x in input().split()]
        ob = Solution()
        ans = ob.subsetSums(arr, N)
        ans.sort()
        for x in ans:
            print(x,end=" ")
        print("")

# } Driver Code Ends