class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        # print(Counter(arr))
        for char,freq in Counter(arr).items():
            if freq>len(arr)/4:
                return char