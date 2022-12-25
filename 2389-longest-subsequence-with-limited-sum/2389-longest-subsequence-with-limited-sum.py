
class Solution:
    def answerQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        sortedNums,ans=sorted(nums),[]
        for query in queries:
            sumOfDigits,lengthOfSubarray,flag=0,0,False
            for number in sortedNums:
                if number+sumOfDigits > query :
                    ans.append(lengthOfSubarray)
                    break
                else:
                    sumOfDigits+=number
                    lengthOfSubarray+=1
            if sum(nums) <= query: ans.append(lengthOfSubarray)
        return ans