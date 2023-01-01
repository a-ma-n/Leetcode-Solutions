class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        wordMap=dict()
        if len(pattern)!=len(wordList:=s.split()): return False
        for patternLetter,word in zip(pattern,wordList):
            if patternLetter not in wordMap and word not in wordMap.values(): wordMap[patternLetter]=word
            elif patternLetter in wordMap and wordMap[patternLetter]!=word: return False
            elif patternLetter not in wordMap and word in wordMap.values(): return False
                
#         for index,patternLetter in enumerate(pattern):
#             if patternLetter not in wordMap:
#                 if wordList[index] in wordMap.values(): return False
                
#             elif wordMap[patternLetter] != wordList[index]:  return False
        return True