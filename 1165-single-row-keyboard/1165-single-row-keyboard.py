class Solution:
    def calculateTime(self, keyboard: str, word: str) -> int:    
        wordMap={letter:index for index,letter in enumerate(keyboard)}
        previousPosn=0
        sum=0
        for index,letter in enumerate(word):
            sum+=abs(wordMap[letter]-previousPosn)
            previousPosn=wordMap[letter]
        return sum
        