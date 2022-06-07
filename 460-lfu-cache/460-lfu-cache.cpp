struct Node{
    int key,value,cnt;
    Node* next;
    Node* prev;
    Node(int _key,int _value){
        key = _key;
        value = _value;
        cnt = 1;
    }
};
struct List{
    int size;
    Node* head;
    Node* tail;
    // List Initialisation
    List(){
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    
    void addFront(Node* node){
        // initialise a new node
        Node* temp = head->next;
        // insert node at the beginning
        node->next = temp;
        node->prev = head;
        // join the ends to the newly inserted node
        head->next = node;
        temp->prev = node;
        // increase the size of the list
        size++;
    }
    
    void removeNode(Node* delnode){
        // store the next and the previous ndoe to the delnode
        Node* delprev = delnode->prev;
        Node* delnext = delnode->next;
        //  attach the end together
        delprev->next = delnext;
        delnext->prev = delprev;
        // decrease the size
        size--;
    }
};
class LFUCache {
    map<int,Node*> keyNode;
    map<int,List*> freqListMap;
    int maxSizeCache;
    int minFreq;
    int curSize;
public:
    // intilisation of the cache 
    LFUCache(int capacity) {
        maxSizeCache = capacity;
        minFreq = 0;
        curSize = 0;
    }
    
    void updateFreqListMap(Node *node){
        
        keyNode.erase(node->key);
        // 1th index (frequency == 1) => remove(node) 
        freqListMap[node->cnt]->removeNode(node);
        
        if(node->cnt == minFreq && freqListMap[node->cnt]->size == 0){
            minFreq++;
        }
    
        List* nextHigherFreqList = new List();
        
        // if we already have a higher frequency list available
        if(freqListMap.find(node->cnt + 1) != freqListMap.end()){
            // update the count of that node
            nextHigherFreqList = freqListMap[node->cnt+1];
        }
        // increment the count
        node->cnt += 1;
        // add a node to the next higher frequency list 
        nextHigherFreqList->addFront(node);
        // update the frequency list map
        freqListMap[node->cnt] = nextHigherFreqList;
        // store the node in the keyNode with the key in the keyNode map
        keyNode[node->key] = node;
    }
    
    int get(int key) {
        // If we are able to find the key , update the frequency list map
        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            int val = node->value;
            updateFreqListMap(node);
            return val;
        }
        // if we are not able to find. a key
        return -1;
    }
    
    void put(int key, int value) {
        if(maxSizeCache == 0){
            return;
        }
        // If node exists
        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            node->value = value;
            updateFreqListMap(node);
        }
        // If node does not exist , create a new one
         else {
            // If the current size = max size of cache
            if(curSize == maxSizeCache) {
                // get the list with min frequency
                List* list = freqListMap[minFreq]; 
                // erase the key of the node just previous to the til in the keyNode map
                keyNode.erase(list->tail->prev->key); 
                // adding to the list with minimum frequency
                freqListMap[minFreq]->removeNode(list->tail->prev);
                // decreasing the cur size
                curSize--; 
            }
             
            curSize++; 
            // new value has to be added who is not there previously 
            // initialise minimum frequency with 1 
            minFreq = 1; 
             
            // create a new list for storing frequency => listfrequency
            List* listFreq = new List(); 
            // if we find a list with min frequenct not present in the map
            if(freqListMap.find(minFreq) != freqListMap.end()) {
                listFreq = freqListMap[minFreq]; 
            }
            // create a new node 
            Node* node = new Node(key, value); 
            // add a new node in the front
            listFreq->addFront(node);
            // add a new key value pair in the keyNode map
            keyNode[key] = node; 
            // create a new pair of min frequency -> list , and store it in a frequency list map
            freqListMap[minFreq] = listFreq; 
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */