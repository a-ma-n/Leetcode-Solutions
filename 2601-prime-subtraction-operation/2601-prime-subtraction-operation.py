class Solution:
    def primeSubOperation(self, nums: List[int]) -> bool:
        
        def isStrictlyIncreasing(nums):
            for i in range(1,len(nums)):
                if nums[i]<=nums[i-1]:
                    return False
            return True
        
        # print(isStrictlyIncreasing([1,2,3]))
        
        if isStrictlyIncreasing(nums): return True
        
        def SieveOfEratosthenes(n):
            prime = [True for i in range(n+1)]
            p = 2
            while(p * p <= n):

                # If prime[p] is not changed, then it is
               # a prime
                if (prime[p] == True):
                    # Update all multiples of p
                    for i in range(p * p, n + 1, p):
                        prime[i] = False
                p += 1
            c = 0
            ans=[]
            # Print all prime numbers
            for p in range(2, n):
                if prime[p]:
                    ans.append(p)
            return ans
        
        def getGreatestPrime(n,ind):
            if n<2:
                return 0
            greatestPrime=2
            primes=SieveOfEratosthenes(n)[::-1]
            print(primes)
            for i in primes:
                    if ind >0 and nums[ind-1] <nums[ind]-i:
                        return i
                    elif ind==0:
                        return i
            return 0
                
        for i,j in enumerate(nums):
            nums[i]-=getGreatestPrime(j,i)
            # print(nums)
            if isStrictlyIncreasing(nums): return True
        
        return isStrictlyIncreasing(nums)
    

"""[6,8,11,12]
[5,8,3]
[2,2]"""