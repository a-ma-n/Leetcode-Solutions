class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        if len(pattern)!=len(wordList:=s.split()): return False
        wordMap=dict()
        for patternLetter,word in zip(pattern,wordList):
            if patternLetter not in wordMap and word not in wordMap.values(): wordMap[patternLetter]=word
            elif patternLetter not in wordMap and word in wordMap.values() or patternLetter in wordMap and wordMap[patternLetter]!=word: return False
        return True