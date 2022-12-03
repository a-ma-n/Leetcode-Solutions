class Solution:
    def calculateTime(self, keyboard: str, word: str) -> int:    
        wordMap={letter:index for index,letter in enumerate(keyboard)}
        #print(wordMap)
        previousPosn=0
        sum=0
        for index,letter in enumerate(word):
            diff=wordMap[letter]-previousPosn
            sum+=abs(diff)
            # print(diff)
            previousPosn=wordMap[letter]
        return sum
        