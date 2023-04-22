class Solution:
    def shortestDistance(self, words: List[str], word1: str, word2: str) -> int:
        size = len(words)
        index1, index2 = size, size
        ans = size

        for i in range(size):
            if words[i] == word1:
                index1 = i
                ans = min(ans, abs(index1-index2))
            elif words[i] == word2:
                index2 = i
                ans = min(ans, abs(index1-index2))
        return ans