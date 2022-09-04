class AllOne {
public:
    AllOne() {   
    }
    map<string,int>mp;
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> mini;
    priority_queue<pair<int, string>> maxi;

    
    void inc(string key) {
        mp[key]++;
        mini.push({mp[key],key});
        maxi.push({mp[key],key});
    }
    
    void dec(string key) {
        mp[key]--;
        mini.push({mp[key],key});
        maxi.push({mp[key],key});
    }
    
    string getMaxKey() {
        while(maxi.size()){
            // at top of maximum heap the frequency == frequency of the (name of the max freq of heap) in the map 
            // also check if the frequency is 0 then cancel the operaation
            if(maxi.top().first == mp[maxi.top().second] && mp[maxi.top().second]){
                return maxi.top().second;
            }
            else{
                maxi.pop();
            }
        }
        return "";
    }
    
    string getMinKey() {
        while(mini.size()){
            if(mini.top().first == mp[mini.top().second] && mp[mini.top().second]){
                return mini.top().second;
            }
            else{
                mini.pop();
            }
        }
        return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */