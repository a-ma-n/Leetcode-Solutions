
class Solution:
    def answerQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        sortedNums=sorted(nums)
        ans=[]
        for query in queries:
            sumOfDigits,lengthOfSubarray,flag=0,0,False
            for number in sortedNums:
                if number+sumOfDigits > query :
                    ans.append(lengthOfSubarray)
                    break
                else:
                    sumOfDigits+=number
                    lengthOfSubarray+=1
            # print("-",sum(nums),query)
            if sum(nums) <= query:
                    # print("k")
                    ans.append(lengthOfSubarray)
            # print(query,lengthOfSubarray,sumOfDigits)
        return ans