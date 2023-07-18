class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        N=len(nums)
        ans = []
        ds = []


        def findSubsets(ind: int):
            ans.append(ds[:])
            for i in range(ind, len(nums)):
                if i != ind and nums[i] == nums[i - 1]:
                    continue
                ds.append(nums[i])
                findSubsets(i + 1)
                ds.pop()
        nums.sort()
        findSubsets(0)
        return ans
                
        self.a=list()
        # self.a.sort(key=(lambda x : len(x)))
        # o=[[2,1,2,1,3],[2,1,2,1],[2,2,1,3],[2,2,1],[2,1,1,3],[2,1,1],[2,1,3],[2,1],[2,2,3],[2,2],[2,3],[2],[1,2,1,3],[1,2,1],[1,1,3],[1,1],[1,3],[1],[3],[]]
        # e=[[1],[1,1],[1,1,2],[1,1,2,2],[1,1,2,2,3],[1,1,2,3],[1,1,3],[1,2],[1,2,2],[1,2,2,3],[1,2,3],[1,3],[2],[2,2],[2,2,3],[2,3],[3]]
        # print(len(o),len(e))
        findSubsets(0)
        return self.a
