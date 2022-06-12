class Trie {
    
private:
    struct TrieNode{
        // 26 links to node children , as we assume that the first letter could possibly be anything
        struct TrieNode*child[26];
        // flag to mark the end of the word
        bool isEnd;
    };
    
// first node
TrieNode* node;
    
public:
    Trie() {
        node = new TrieNode();
    }
    
    /*
    Time complexity : O(m)O(m)
    Space complexity : O(m)O(m)
    */
    void insert(string word) {
        TrieNode* cur = node;
        for(char c : word){
            // create a new child for all the elements where there doesnot exist already a link
            if(cur->child[c-'a'] == NULL) cur->child[c-'a'] = new TrieNode();
            // move the cur node pointer to the next child element
            // * we always subtract 'a' because the c we have will be b/w 97-122 ASCII 
            //=> now we have indexes: 0-25 ( indexed from 0 -> the child nodes we created in the struct)
            
            // so we need to subtract that to  get our value
            cur=cur->child[c-'a'];
        }
        // we mark this when we reach the end of the trie, since we are insertunf 
        cur->isEnd=true;
    }
    
    /*
    Time complexity : O(m)O(m)
    Space complexity : O(1)O(1)
    */
    bool search(string word) {
        TrieNode* cur = node;
        for(char c:word){
            // if even the starting value doesnot exist return false
            if(cur->child[c-'a'] == NULL) return false; 
            // if it exists move the cur pointer to the next child node
            cur = cur->child[c-'a'];
        }
        // if we found that the flag is true -> word completed => return true
        if(cur->isEnd==true ) return true;
        return false;
    }
    /*
    Time complexity : O(m)O(m)
    Space complexity : O(1)O(1)
    */
    // going to find prefix => everything same as search + remove the last condition of the flag isEnd
    bool startsWith(string prefix) {
        TrieNode* cur = node;
        for(char c:prefix){
            if(cur->child[c-'a']==NULL) return false;
            cur=cur->child[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */