class MovingAverage:
    nums=[]
    index=0
    def __init__(self, size: int):
        self.nums=[0]*size
        # sel
        pass

    def next(self, val: int) -> float:
        self.nums[self.index%len(self.nums)]=val
        self.index+=1
        # print(self.nums)
        if self.index<len(self.nums):
            return sum(self.nums)/self.index
        return sum(self.nums)/len(self.nums)


# Your MovingAverage object will be instantiated and called as such:
# obj = MovingAverage(size)
# param_1 = obj.next(val)