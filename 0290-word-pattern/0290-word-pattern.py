class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        wordMap=dict()
        wordList=s.split()
        if len(pattern)!=len(wordList): return False
        for index,patternLetter in enumerate(pattern):
            
            if patternLetter not in wordMap:
                if wordList[index] in wordMap.values(): 
                    return False
                wordMap[patternLetter]=wordList[index]
            elif wordMap[patternLetter] != wordList[index]: 
                return False
            
        return True
        