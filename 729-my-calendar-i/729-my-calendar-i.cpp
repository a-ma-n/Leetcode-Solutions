class MyCalendar {
public:
    vector<pair<int,int>> crr;
    MyCalendar() {     
    }
    
    bool book(int start, int end) {
        if(crr.size()==0) {
            crr.push_back({start,end});
            return true;
        }
        for(auto it:crr){
            if(it.first<=start && it.second>start) return false;
            if(start<=it.first && end>it.first ) return false;
        }
        crr.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */