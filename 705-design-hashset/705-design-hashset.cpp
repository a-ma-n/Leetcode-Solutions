class MyHashSet {
public:
    vector<int> v;
    int pos;
    MyHashSet() {
        
    }
    
    void add(int key) {
        if(!contains(key)){
            // add new element
            v.push_back(key);
        }
    }
    
    void remove(int key) {
        if(contains(key)){
            // remove element
             v.erase(v.begin()+pos);
        }
    }
    
    bool contains(int key) {
        for(int i=0;i<v.size();i++){
            if(v[i]==key){
                pos=i;
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */