class HitCounter {
private:
    queue<int> hits;
    
public:
    /** Initialize your data structure here. */
    HitCounter() {
        
    }
     /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        this-> hits.push(timestamp);
    }
    
     /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        while(!this->hits.empty()){
            int diff = timestamp - this->hits.front();
            if(diff >= 300) this->hits.pop();
            else break;
        }
        return this->hits.size();
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */