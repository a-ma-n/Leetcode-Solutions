class TrieNode:
    def __init__(self):
        self.children = defaultdict(TrieNode)
        self.prefixCount = 0

class Trie:
    def __init__(self, words: List[str]):
        self.trie = TrieNode()
        for word in words:
            self.insert(word)
        self.prefixScores = {}

    def insert(self, word: str) -> None:
        currentNode = self.trie
        for char in word:
            currentNode = currentNode.children[char]
            currentNode.prefixCount += 1

    def prefixScore(self, word: str) -> None:
        if word not in self.prefixScores:
            self.prefixScores[word] = 0
            currentNode = self.trie
            for char in word:
                currentNode = currentNode.children[char]
                self.prefixScores[word] += currentNode.prefixCount
        return self.prefixScores[word]

class Solution:
    def sumPrefixScores(self, words: List[str]) -> List[int]:        
        wordTrie = Trie(words)
        return [wordTrie.prefixScore(word) for word in words]