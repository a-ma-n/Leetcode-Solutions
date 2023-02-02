class Solution:
    def areSentencesSimilar(self, sentence1: List[str], sentence2: List[str], similarPairs: List[List[str]]) -> bool:
        if len(sentence1)!=len(sentence2): return False
        if ''.join(sentence1)==''.join(sentence2): return True
        for i,j in zip(sentence1,sentence2):
            if [i,j] not in similarPairs and [j,i] not in similarPairs and i!=j:
                print(i,j)
                return False
        return True
                