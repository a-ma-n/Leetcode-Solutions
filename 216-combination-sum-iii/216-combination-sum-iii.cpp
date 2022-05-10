class Solution {
public:
    
    vector<vector<int>> res;
    
    void sum(int cnum,int k,int n,vector<int> cur){
        if(n < 0 || cur.size() > k) return;
        
        
         if(n == 0 && cur.size() == k) {
           res.push_back(cur);
            return;
        }
        
        for(int i=cnum;i<=9;++i){
            cur.push_back(i);
            sum(i+1,k,n-i,cur);
            cur.pop_back();
        }
    }        
    
    
    
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<int> cur;
        sum(1,k,n,cur);
        return res;
        
    }
};