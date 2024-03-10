class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        maxFrequency=Counter(nums).most_common(1)[0][1]
        print(maxFrequency)
        return sum( [ curFrequency==maxFrequency for char,curFrequency in Counter(nums).items()])*maxFrequency
        # print(Counter(nums))
        # return Counter(nums).most_common