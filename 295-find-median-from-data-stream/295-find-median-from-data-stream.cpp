class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;    
    MedianFinder() {}
    
    void addNum(int num) {
        // input in decreasing order 1 2 3
        if(minHeap.empty() || num>=minHeap.top()){
            minHeap.push(num);
            if( minHeap.size() > maxHeap.size() + 1){
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
        else{ // input in decreasing order 3 2 1 
            maxHeap.push(num);
            if(maxHeap.size() > minHeap.size()){
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
        }
    }
    
    double findMedian() {
        if( (maxHeap.size() + minHeap.size())%2 == 0 ){
            return (double) (minHeap.top() + maxHeap.top())/2;
        }
        else{
            return minHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */