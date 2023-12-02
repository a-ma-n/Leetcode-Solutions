class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        goodCount=0
        for word in words:
            # print(Counter(chars),Counter(word))
            if Counter(chars)>=Counter(word):
                goodCount+=len(word)
        return goodCount