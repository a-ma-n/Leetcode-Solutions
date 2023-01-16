class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        # edge case of empty intervals
        if len(intervals) == 0:
            return [newInterval]
            
        #Finding new interval's right place
        index_to_insert = 1
        for i in range(len(intervals)):
            if intervals[i][0] >= newInterval[0]:
                index_to_insert = i
                break
            if i == len(intervals) - 1:
                index_to_insert = -1
                
        # Inserting there
        if index_to_insert == -1:
            intervals.append(newInterval)
        else:
            intervals.insert(index_to_insert, newInterval)

        # Merging if necessary
        final = [intervals[0]]
        for i in range(1, len(intervals)):
            if intervals[i][0] <= final[-1][1]:
                final[-1] = [final[-1][0], max(final[-1][1], intervals[i][1])]
            else:
                final.append(intervals[i])
        return final