class Solution:
    def minWindow(self, s: str, t: str) -> str:
        candidates = collections.Counter(t)
        required = len(candidates)
        matched = 0
        counter = collections.Counter()
        min_length = float('inf')
        res = ""
        start = 0
        
        for end, c in enumerate(s):
            if c in candidates:
                counter[c] += 1
                if counter[c] == candidates[c]:
                    matched += 1
            while matched == required:
                if end - start + 1 < min_length:
                    res = s[start:end+1]
                    min_length = end - start + 1
                if s[start] in candidates:
                    counter[s[start]] -= 1
                    if counter[s[start]] < candidates[s[start]]:
                        matched -= 1
                start += 1
        return res