class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        
        def areLexicographicallySorted(word1,word2):
            minLen=min(len(word1),len(word2))
            for i in range(minLen):
                # print(order.index(word1[i]),order.index(word2[i]),word1[i],word2[i])
                if order.index(word1[i])<order.index(word2[i]):
                    return True
                elif order.index(word1[i])>order.index(word2[i]):
                    return False
                else:
                    continue
            print(word1[:minLen],word2[:minLen],len(word1),len(word2),len(word1)<len(word2))
            if word1[:minLen]==word2[:minLen]: return len(word1)<=len(word2)
            return True
    
        for i in range(1,len(words)):
            if not areLexicographicallySorted(words[i-1],words[i]):
                print(words[i-1],words[i])
                return False
        return True