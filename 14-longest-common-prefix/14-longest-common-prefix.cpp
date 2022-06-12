class TrieNode{
public:
    unordered_map<char, TrieNode*> children;
    char val;
    bool isWord = false;
    
    TrieNode(){}
    
    TrieNode(char v){
        this->val = v;
    }
};

class Trie{
private:
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /* Get TrieNode. */
    TrieNode* getTrieNode(){
        return root;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* temp = root;
        
        for(auto ch : word){
            if(temp->children.find(ch) == temp->children.end()){
                temp->children[ch] = new TrieNode(ch);
            }     
            temp = temp->children[ch];
        }
        
        temp->isWord = true;
    }

};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // insert all keys into trie
        Trie* pTrie = new Trie();
        
        for (string str : strs) { pTrie->insert(str); }

        // Traverse the trie and find Longest Common Prefix
        string lcp("");
        TrieNode* curr = pTrie->getTrieNode();

        // Do till we find a leaf node or node has more than 1 children
        while (curr && !curr->isWord && (curr->children.size() == 1))
        {
            auto it = curr->children.begin();
            lcp += it->first;
            curr = it->second;
        }

        return lcp;
    }
};