class MyCalendar {
public:
    // we will store the start,end indexes in the booking array
    vector<pair<int,int>> booking;
    // we will store the end,start indexes in the set
    set<pair<int,int>> s;
    
    MyCalendar() {     
    }
    
    bool book(int start, int end) {
        // it converts tyhe input in such a way such that the highher val is stores as first and the lower as the second valiue
       auto it=s.upper_bound({start,end});
        cout<<it->first<<" "<<it->second<<endl;
        //if the vector is not null   && 
        // the smaller value is less than the end value => the intervals are overlapping
        if(it!=s.end() && it->second<end)
            return false;
        // if the intervals dont overlap then add it to the set
        s.insert({end,start});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */