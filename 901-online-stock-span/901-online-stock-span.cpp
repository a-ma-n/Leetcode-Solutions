class StockSpanner {
public:
    int i =0;
    stack<int> st;
    vector<int> v;
    
    StockSpanner() {    
    }
    
    int next(int price) {
        //
        v.push_back(price);
        // if stack is not empty and the top most element which is actually the greatest is smaller than price then
        // v[st.top] as st stores the index of the element
        while(!st.empty() && price >= v[st.top()]){
            st.pop();
        }
        // putting -1 gives 1 if an element does not have next left greater element
        int k = ( st.empty() ) ? -1 :st.top();
        st.push(i);
        i++; 
        // increment value of the index as we keep on storing the different element
        // we return the current index - the index of the next left larger element
        return i-k-1;;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */